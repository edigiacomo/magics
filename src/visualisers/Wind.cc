/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file Wind.cc
    \brief Implementation of the Template class Wind.

    Magics Team - ECMWF 2005

    Started: Thu 17-Mar-2005

    Changes:

*/

#include "Wind.h"

#include "ContourLibrary.h"
#include "CustomisedPoint.h"
#include "HistoVisitor.h"
#include "Layout.h"
#include "MatrixHandler.h"
#include "MagicsGlobal.h"
#include "MetaData.h"

using namespace magics;


Wind::Wind() {}


Wind::~Wind() {}

/*!
 Class information are given to the output-stream.
*/

void Wind::print(ostream& out) const {
    out << "Wind";
}


void Wind::operator()(Data& data, BasicGraphicsObjectContainer& parent) {

    // Automatic Styling ?

    bool legend = type_->legend_only_;

    try {
        ParameterManager::set("contour_automatic_library_path", library_path_);
        ContourLibrary* library = MagTranslator<string, ContourLibrary>()(setting_);

        MetaDataCollector meta, needAttributes;

       

        if (predefined_.size()) {
            library->getStyle(predefined_, automaticAttributes_);
            set(automaticAttributes_);
            automaticAttributes_["wind_legend_only"] = type_->legend_only_;
        }
        
        else {
            library->askId(meta);
            data.visit(meta);
            if (library->checkId(meta, needAttributes)) {
                data.visit(needAttributes);
                needAttributes["theme"] = theme_;
                automaticAttributes_["wind_legend_only"] = type_->legend_only_;
                library->getStyle(needAttributes, automaticAttributes_, *styleInfo_);
                set(automaticAttributes_);
            }
            else {
                meta["theme"] = theme_;
                styleInfo_       = new StyleEntry();

                library->getStyle(meta, automaticAttributes_, *styleInfo_);
                automaticAttributes_["wind_legend_only"] = type_->legend_only_;
               
                if  (getEnvVariable("MAGICS_STYLES_DEBUG") != "") {
                    for (auto s = automaticAttributes_.begin(); s != automaticAttributes_.end(); ++s)
                        cout << s->first << "-->" << s->second << endl;
                }
                set(automaticAttributes_);

            }
        }
    }
    catch (MagicsException& e) {
        throw;  // forwarding exception
    }

    if (legend)
        return;


    if ((*type_)(data, parent))
        return;
    

    ThinningMethod* method = 0;

    const Transformation& transformation = parent.transformation();

    try {
        method = MagTranslator<string, ThinningMethod>()(this->thinning_method_);
    }
    catch (...) {
        if (MagicsGlobal::strict()) {
            throw;
        }
    }
    if (!method)
        method = new BasicThinningMethod();

    method->set2D();

    this->factor_   = maground(this->thinning_factor_);
    this->nbPoints_ = this->thinning_factor_;
    this->rawOnly_  = false;
    this->height_   = parent.absoluteHeight();
    this->width_    = parent.absoluteWidth();
    method->set(*this);


    CustomisedPointsList points;
    std::set<string> request;
    request.insert("x_component");
    request.insert("y_component");
    request.insert("colour_component");
    // if ( thinning_debug_ )
    // request.insert("debug");
    (*method)(data, transformation, request, points);
    if (points.empty())
        return;


    (*this->type_).prepare(parent, method->units());

    (*this->type_).adjust(points, transformation);


    

    for (const auto& point : points) {
        bool north    = (point->latitude() > 0);
        double x      = point->longitude();
        double y      = point->latitude();
        PaperPoint xy = transformation(UserPoint(point->longitude(), point->latitude()));
        if (transformation.inExtended(xy) || point->tile()) {
            pair<double, double> component = std::make_pair((*point)["x_component"], (*point)["y_component"]);
            transformation.reprojectComponents(x, y, component);
            (*this->type_)(north, xy, component.first, component.second, (*point)["colour_component"]);
        }
    }
    (*this->type_).finish(parent);
}


void Wind::visit(LegendVisitor& legend) {
    (*this->type_).visit(legend);
}

void Wind::visit(Data& data, HistoVisitor& visitor) {
    // if ( !matrix_ )
    //	return;

    (*this->type_).visit(data, data.points(*visitor.dataLayoutTransformation(), false), visitor);
}
