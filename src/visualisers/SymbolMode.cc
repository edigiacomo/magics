/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file SymbolMode.cc
    \brief Implementation of the Template class SymbolMode.

    Magics Team - ECMWF 2004

    Started: Wed 21-Jan-2004

    Changes:

*/


#include "SymbolMode.h"
#include "CartesianTransformation.h"
#include "HistoVisitor.h"
#include "Histogram.h"
#include "LegendVisitor.h"
#include "SymbolPlotting.h"
#include "MagicsGlobal.h"

using namespace magics;


SymbolMode::SymbolMode(): scaling_(1) {}


SymbolMode::~SymbolMode() {}
void SymbolMode::visit(Data& data, HistoVisitor& visitor) {
    IntervalMap<Colour> beans;
    Histogram helper;
    helper.visit(beans, data, data.points(*visitor.dataLayoutTransformation(), false), visitor);
}


/*!
 Class information are given to the output-stream.
*/
void SymbolMode::print(ostream& out) const {
    out << "SymbolMode";
}

SymbolIndividualMode::SymbolIndividualMode() {}


SymbolIndividualMode::~SymbolIndividualMode() {}

void SymbolIndividualMode::update() {
    if (magCompare(marker_mode_, "index")) {
        ostringstream symbol;
        symbol << "magics_" << marker_;
        symbol_ = symbol.str();
    }
    current_ = text_.begin();
}

void SymbolIndividualMode::properties() const {
    static map<string, TextPosition> texthandlers;
    if (texthandlers.empty()) {
        texthandlers["none"]   = TextPosition::NONE;
        texthandlers["left"]   = TextPosition::LEFT;
        texthandlers["top"]    = TextPosition::ABOVE;
        texthandlers["bottom"] = TextPosition::BELOW;
        texthandlers["right"]  = TextPosition::RIGHT;
        texthandlers["centre"] = TextPosition::NONE;
    }
    TextPosition position;
    string type                             = lowerCase(text_position_);
    
    map<string, TextPosition>::iterator pos = texthandlers.find(type);
    position                                = (pos != texthandlers.end()) ? pos->second : TextPosition::ABOVE;
    if (magCompare(type_, "text") || magCompare(type_, "number")) {
        properties_.height_ = 0.05;  // make a very small symbol
    }
    else {
        properties_.colour_ = *colour_;
        properties_.height_ = height_*scaling_;
    }
   
    if (magCompare(marker_mode_, "image")) {
        properties_.image_        = true;
        properties_.image_path_   = image_path_;
        properties_.image_width_  = image_width_;
        properties_.image_height_ = image_height_;
        properties_.image_format_ = image_format_;
        properties_.image_by_reference_ = image_by_reference_;
    }

    properties_.outline_              = parent_->outline_;
    properties_.outlineColour_        = *parent_->outline_colour_;
    properties_.outlineStyle_         = parent_->outline_style_;
    properties_.outlineThickness_     = parent_->outline_thickness_;
    properties_.connectLine_          = parent_->connect_;
    properties_.connectLineColour_    = (parent_->automatic_connect_colour_) ? *colour_ : *parent_->connect_colour_;
    properties_.connectLineStyle_     = parent_->connect_style_;
    properties_.connectLineThickness_ = parent_->connect_thickness_;
    properties_.blanking_             = parent_->text_blanking_;

    if (current_ != text_.end()) {
        properties_.label(*current_);
        ++current_;
        if (current_ == text_.end())
            current_ = text_.begin();
    }

    MagFont font(text_font_name_);
    font.colour(text_font_colour_->automatic() ? *colour_ : *text_font_colour_);
    font.size(text_font_size_);
    font.style(text_font_style_);
    properties_.font_     = font;
    properties_.position_ = position;
    properties_.setSymbol(symbol_, 0);
    properties_.text_ = text_;
}

/*!
 Class information are given to the output-stream.
*/
void SymbolIndividualMode::print(ostream& out) const {
    out << "SymbolIndividualMode[";
    SymbolIndividualModeAttributes::print(out);
    out << "]";
}


SymbolTableMode::SymbolTableMode() {}

SymbolTableMode::~SymbolTableMode() {}

/*!
 Class information are given to the output-stream.
*/
void SymbolTableMode::print(ostream& out) const {
    out << "SymbolTableMode[";
    SymbolTableModeAttributes::print(out);
    out << "]";
}


SymbolProperties SymbolTableMode::operator()(double value) const {
    return map_.find(value, SymbolProperties());
}

void SymbolTableMode::prepare() {
    if (colour_.empty()) {
        MagLog::warning() << "SymbolTableMode: No colour table defined.\n";
        colour_.push_back("red");
    }
    if (height_.empty()) {
        MagLog::warning() << "SymbolTableMode: No height table defined.\n";
        height_.push_back(0.2);
    }
    if (!marker_.empty()) {
        symbol_.clear();
        for (vector<int>::const_iterator marker = marker_.begin(); marker != marker_.end(); ++marker)
            symbol_.push_back(Symbol::convert(*marker));
    }

    if (symbol_.empty()) {
        MagLog::warning() << "SymbolTableMode: No marker table defined.\n";
        symbol_.push_back("magics_1");
    }
    doublearray::iterator max    = max_.begin();
    stringarray::iterator colour = colour_.begin();
    doublearray::iterator height = height_.begin();
    stringarray::iterator symbol = symbol_.begin();

    int index = 0;

    for (doublearray::const_iterator min = min_.begin(); min != min_.end(); ++min) {
        map_[Interval(*min, *max)]           = SymbolProperties(Colour(*colour), *height*scaling_, *symbol);
        map_[Interval(*min, *max)].blanking_ = parent_->text_blanking_;
        if (++colour == colour_.end())
            --colour;
        if (++height == height_.end())
            --height;
        if (++symbol == symbol_.end())
            --symbol;
        //        label << *min << "-" << *max;
        //        map[index].label_ = label.str();

        if (++max == max_.end())
            --max;
        index++;
    }
}

bool SymbolTableMode::accept(double value) {
    try {
        map_.find(value);
        return true;
    }
    catch (...) {
        if (MagicsGlobal::strict()) {
            throw;
        }
        return false;
    }
}


void SymbolTableMode::visit(LegendVisitor& legend) {
    IntervalMap<SymbolProperties>::const_iterator interval;

    for (interval = map_.begin(); interval != map_.end(); ++interval) {
        Symbol* symbol = new Symbol();
        (*symbol).setColour(interval->second.colour_);
        (*symbol).setSymbol(interval->second.marker_);
        (*symbol).setHeight(interval->second.height_);
        legend.add(new SimpleSymbolEntry(interval->first.min_, interval->first.max_, symbol));
    }
    legend.last();
}

void SymbolTableMode::visit(Data& data, HistoVisitor& visitor) {
    IntervalMap<Colour> beans;
    if (!visitor.basic())
        buildBins(map_, beans);
    Histogram helper;
    helper.visit(beans, data, data.points(*visitor.dataLayoutTransformation(), false), visitor);
}

void SymbolTableMode::buildBins(const IntervalMap<SymbolProperties>& in, IntervalMap<Colour>& out) {
    for (IntervalMap<SymbolProperties>::const_iterator interval = in.begin(); interval != in.end(); ++interval)
        out.insert(make_pair(Interval(interval->first.min_, interval->first.max_), interval->second.colour_));
}

void SymbolIndividualMode::visit(LegendVisitor& legend) {
    Symbol* symbol = properties_.symbol("marker");
    // overwrite with the legend_height if set..
    if (legend_height_ != -1)
        // symbol->setHeight(legend_height_);
        symbol->setHeight(0.5);
    legend.add(new SimpleSymbolEntry(legend_text_, symbol));
}

void SymbolIndividualMode::visit(Data& data, LegendVisitor& legend) {
    Symbol* symbol = properties_.symbol("marker");
    if (legend_height_ != -1)
        symbol->setHeight(legend_height_);
    SimpleSymbolEntry* entry = new SimpleSymbolEntry(legend_text_, symbol);
    entry->userText(legend_text_, "user");
    legend.add(entry);
}

void SymbolTableMode::visit(Data& data, LegendVisitor& legend) {
    legend.newLegend();

    switch (legend.legendType()) {
        case LegendMethod::CONTINUOUS: {
            for (IntervalMap<SymbolProperties>::const_iterator interval = map_.begin(); interval != map_.end();
                 ++interval) {
                Polyline* box = new Polyline();

                double min = interval->first.min_;
                double max = interval->first.max_;

                box->setShading(new FillShadingProperties());

                box->setFillColour(interval->second.colour_);
                box->setFilled(true);

                legend.add(new BoxEntry(min, max, box));
            }
            break;
        }
        case LegendMethod::DISJOINT: {
            for (IntervalMap<SymbolProperties>::iterator interval = map_.begin(); interval != map_.end(); ++interval) {
                Symbol* symbol = new Symbol();
                (*symbol).setColour(interval->second.colour_);
                (*symbol).setSymbol(interval->second.marker_);
                (*symbol).setHeight(interval->second.height_);

                string str = data.legendText(interval->first.min_, interval->first.max_);
                if (str.empty()) {
                    ostringstream text;
                    text << interval->first.min_ << "-" << interval->first.max_;
                    str = text.str();
                }
                legend.add(
                    new SimpleSymbolEntry(interval->second.label_.empty() ? str : interval->second.label_, symbol));
            }
            break;
        }
        case LegendMethod::HISTOGRAM: {
            IntervalMap<Colour> beans;
            buildBins(map_, beans);
            Histogram helper;
            // here we need the transformation.. to know wich points where displayed!
            IntervalMap<int>& histogram = helper.histogram(beans, data.points(legend.transformation(), false));

            int total = 0;
            for (IntervalMap<int>::const_iterator interval = histogram.begin(); interval != histogram.end();
                 ++interval) {
                total += interval->second;
            }
            bool first = true;
            for (IntervalMap<SymbolProperties>::const_iterator interval = map_.begin(); interval != map_.end();
                 ++interval) {
                Polyline* box = new Polyline();

                double min = interval->first.min_;
                double max = interval->first.max_;

                box->setShading(new FillShadingProperties());
                box->setFillColour(interval->second.colour_);
                box->setFilled(true);
                BoxEntry* entry = new BoxEntry(min, max, box);
                int count       = histogram.find(min, -1);
                entry->population(count);
                entry->totalPopulation(total);
                if (first) {
                    entry->first();
                    first = false;
                }
                legend.add(entry);
            }
        }
    }
    legend.last();
}
