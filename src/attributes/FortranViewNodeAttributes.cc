
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file FortranViewNodeAttributes.h
    \\brief Definition of FortranViewNode Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "FortranViewNodeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

FortranViewNodeAttributes::FortranViewNodeAttributes():
	left_(ParameterManager::getDouble("subpage_x_position")),
	bottom_(ParameterManager::getDouble("subpage_y_position")),
	width_(ParameterManager::getDouble("subpage_x_length")),
	height_(ParameterManager::getDouble("subpage_y_length")),
	predefined_(ParameterManager::getBool("subpage_map_library_area")),
	predefined_name_(ParameterManager::getString("subpage_map_area_name")),
	bottom_internal_(ParameterManager::getDouble("subpage_y_position_internal")),
	left_internal_(ParameterManager::getDouble("subpage_x_position_internal")),
	right_(ParameterManager::getDouble("subpage_right_position")),
	height_internal_(ParameterManager::getDouble("subpage_y_length_internal")),
	width_internal_(ParameterManager::getDouble("subpage_x_length_internal")),
	top_(ParameterManager::getDouble("subpage_top_position")),
	clipping_(ParameterManager::getBool("subpage_clipping")),
	frame_(ParameterManager::getBool("subpage_frame")),
	frame_thickness_(ParameterManager::getInt("subpage_frame_thickness")),
	vertical_axis_with_(ParameterManager::getDouble("subpage_vertical_axis_width")),
	horizontal_axis_height_(ParameterManager::getDouble("subpage_horizontal_axis_height")),
	overlay_(ParameterManager::getString("subpage_map_overlay_control")),
	horizontal_(ParameterManager::getString("subpage_align_horizontal")),
	vertical_(ParameterManager::getString("subpage_align_vertical")),
	json_(ParameterManager::getString("subpage_map_json_definition")),
	title_(ParameterManager::getBool("automatic_title")),
	expand_(ParameterManager::getBool("subpage_expand_mode"))
	,
	transformation_(MagTranslator<string, Transformation>().magics("subpage_map_projection")),
	background_(MagTranslator<string, Colour>().magics("subpage_background_colour")),
	frame_colour_(MagTranslator<string, Colour>().magics("subpage_frame_colour")),
	frame_line_style_(MagTranslator<string, LineStyle>().magics("subpage_frame_line_style")),
	preview_(MagTranslator<string, NoPreviewVisitor>().magics("subpage_map_preview")),
	magnify_(MagTranslator<string, NoMagnifierVisitor>().magics("subpage_map_magnifier"))
	
{
}


FortranViewNodeAttributes::~FortranViewNodeAttributes()
{

}


void FortranViewNodeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "subpage";
	prefix[i++] = "subpage";
	prefix[i++] = "subpage";
	
	setAttribute(prefix, "subpage_x_position", left_, params);
	setAttribute(prefix, "subpage_y_position", bottom_, params);
	setAttribute(prefix, "subpage_x_length", width_, params);
	setAttribute(prefix, "subpage_y_length", height_, params);
	setAttribute(prefix, "subpage_map_library_area", predefined_, params);
	setAttribute(prefix, "subpage_map_area_name", predefined_name_, params);
	setAttribute(prefix, "subpage_y_position_internal", bottom_internal_, params);
	setAttribute(prefix, "subpage_x_position_internal", left_internal_, params);
	setAttribute(prefix, "subpage_right_position", right_, params);
	setAttribute(prefix, "subpage_y_length_internal", height_internal_, params);
	setAttribute(prefix, "subpage_x_length_internal", width_internal_, params);
	setAttribute(prefix, "subpage_top_position", top_, params);
	setAttribute(prefix, "subpage_clipping", clipping_, params);
	setAttribute(prefix, "subpage_frame", frame_, params);
	setAttribute(prefix, "subpage_frame_thickness", frame_thickness_, params);
	setAttribute(prefix, "subpage_vertical_axis_width", vertical_axis_with_, params);
	setAttribute(prefix, "subpage_horizontal_axis_height", horizontal_axis_height_, params);
	setAttribute(prefix, "subpage_map_overlay_control", overlay_, params);
	setAttribute(prefix, "subpage_align_horizontal", horizontal_, params);
	setAttribute(prefix, "subpage_align_vertical", vertical_, params);
	setAttribute(prefix, "subpage_map_json_definition", json_, params);
	setAttribute(prefix, "automatic_title", title_, params);
	setAttribute(prefix, "subpage_expand_mode", expand_, params);
	
	setMember(prefix, "subpage_map_projection", transformation_, params);
	setMember(prefix, "subpage_background_colour", background_, params);
	setMember(prefix, "subpage_frame_colour", frame_colour_, params);
	setAttribute(prefix, "subpage_frame_line_style", frame_line_style_, params);
	setMember(prefix, "subpage_map_preview", preview_, params);
	setMember(prefix, "subpage_map_magnifier", magnify_, params);
	
}

void FortranViewNodeAttributes::copy(const FortranViewNodeAttributes& other)
{
	left_ = other.left_;
	bottom_ = other.bottom_;
	width_ = other.width_;
	height_ = other.height_;
	predefined_ = other.predefined_;
	predefined_name_ = other.predefined_name_;
	bottom_internal_ = other.bottom_internal_;
	left_internal_ = other.left_internal_;
	right_ = other.right_;
	height_internal_ = other.height_internal_;
	width_internal_ = other.width_internal_;
	top_ = other.top_;
	clipping_ = other.clipping_;
	frame_ = other.frame_;
	frame_thickness_ = other.frame_thickness_;
	vertical_axis_with_ = other.vertical_axis_with_;
	horizontal_axis_height_ = other.horizontal_axis_height_;
	overlay_ = other.overlay_;
	horizontal_ = other.horizontal_;
	vertical_ = other.vertical_;
	json_ = other.json_;
	title_ = other.title_;
	expand_ = other.expand_;
	transformation_ = unique_ptr<Transformation>(other.transformation_->clone());
	background_ = unique_ptr<Colour>(other.background_->clone());
	frame_colour_ = unique_ptr<Colour>(other.frame_colour_->clone());
	frame_line_style_ = other.frame_line_style_;
	preview_ = unique_ptr<NoPreviewVisitor>(other.preview_->clone());
	magnify_ = unique_ptr<NoMagnifierVisitor>(other.magnify_->clone());
	
}


bool FortranViewNodeAttributes::accept(const string& node)
{

	if ( magCompare(node, "subpage")  )
		return true;
	if ( acceptNode(node, transformation_) )
		return true;
	if ( acceptNode(node, preview_) )
		return true;
	if ( acceptNode(node, magnify_) )
		return true;
	
	return false;
}

void FortranViewNodeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "subpage")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), transformation_, node);
		setMember(node.name(), preview_, node);
		setMember(node.name(), magnify_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), transformation_, *elt);
		setMember(elt->name(), preview_, *elt);
		setMember(elt->name(), magnify_, *elt);
		
	}
}

void FortranViewNodeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " left = " <<  left_;
	out << " bottom = " <<  bottom_;
	out << " width = " <<  width_;
	out << " height = " <<  height_;
	out << " predefined = " <<  predefined_;
	out << " predefined_name = " <<  predefined_name_;
	out << " bottom_internal = " <<  bottom_internal_;
	out << " left_internal = " <<  left_internal_;
	out << " right = " <<  right_;
	out << " height_internal = " <<  height_internal_;
	out << " width_internal = " <<  width_internal_;
	out << " top = " <<  top_;
	out << " clipping = " <<  clipping_;
	out << " frame = " <<  frame_;
	out << " frame_thickness = " <<  frame_thickness_;
	out << " vertical_axis_with = " <<  vertical_axis_with_;
	out << " horizontal_axis_height = " <<  horizontal_axis_height_;
	out << " overlay = " <<  overlay_;
	out << " horizontal = " <<  horizontal_;
	out << " vertical = " <<  vertical_;
	out << " json = " <<  json_;
	out << " title = " <<  title_;
	out << " expand = " <<  expand_;
	out << " transformation = " <<  *transformation_;
	out << " background = " <<  *background_;
	out << " frame_colour = " <<  *frame_colour_;
	out << " frame_line_style = " <<  frame_line_style_;
	out << " preview = " <<  *preview_;
	out << " magnify = " <<  *magnify_;
	
	out << "]" << "\n";
}

void FortranViewNodeAttributes::toxml(ostream& out)  const
{
	out <<  "\"subpage\"";
	out << ", \"subpage_x_position\":";
	niceprint(out,left_);
	out << ", \"subpage_y_position\":";
	niceprint(out,bottom_);
	out << ", \"subpage_x_length\":";
	niceprint(out,width_);
	out << ", \"subpage_y_length\":";
	niceprint(out,height_);
	out << ", \"subpage_map_library_area\":";
	niceprint(out,predefined_);
	out << ", \"subpage_map_area_name\":";
	niceprint(out,predefined_name_);
	out << ", \"subpage_y_position_internal\":";
	niceprint(out,bottom_internal_);
	out << ", \"subpage_x_position_internal\":";
	niceprint(out,left_internal_);
	out << ", \"subpage_right_position\":";
	niceprint(out,right_);
	out << ", \"subpage_y_length_internal\":";
	niceprint(out,height_internal_);
	out << ", \"subpage_x_length_internal\":";
	niceprint(out,width_internal_);
	out << ", \"subpage_top_position\":";
	niceprint(out,top_);
	out << ", \"subpage_clipping\":";
	niceprint(out,clipping_);
	out << ", \"subpage_frame\":";
	niceprint(out,frame_);
	out << ", \"subpage_frame_thickness\":";
	niceprint(out,frame_thickness_);
	out << ", \"subpage_vertical_axis_width\":";
	niceprint(out,vertical_axis_with_);
	out << ", \"subpage_horizontal_axis_height\":";
	niceprint(out,horizontal_axis_height_);
	out << ", \"subpage_map_overlay_control\":";
	niceprint(out,overlay_);
	out << ", \"subpage_align_horizontal\":";
	niceprint(out,horizontal_);
	out << ", \"subpage_align_vertical\":";
	niceprint(out,vertical_);
	out << ", \"subpage_map_json_definition\":";
	niceprint(out,json_);
	out << ", \"automatic_title\":";
	niceprint(out,title_);
	out << ", \"subpage_expand_mode\":";
	niceprint(out,expand_);
	out << ", \"subpage_map_projection\":";
	transformation_->toxml(out);
	out << ", \"subpage_background_colour\":";
	niceprint(out, *background_);
	out << ", \"subpage_frame_colour\":";
	niceprint(out, *frame_colour_);
	out << ", \"subpage_frame_line_style\":";
	niceprint(out, frame_line_style_);
	out << ", \"subpage_map_preview\":";
	preview_->toxml(out);
	out << ", \"subpage_map_magnifier\":";
	magnify_->toxml(out);
	
}

static MagicsParameter<double> subpage_x_position("subpage_x_position", -1);
static MagicsParameter<double> subpage_y_position("subpage_y_position", -1);
static MagicsParameter<double> subpage_x_length("subpage_x_length", -1);
static MagicsParameter<double> subpage_y_length("subpage_y_length", -1);
static MagicsParameter<string> subpage_map_library_area("subpage_map_library_area", "off");
static MagicsParameter<string> subpage_map_area_name("subpage_map_area_name", "off");
static MagicsParameter<double> subpage_y_position_internal("subpage_y_position_internal", -1);
static MagicsParameter<double> subpage_x_position_internal("subpage_x_position_internal", -1);
static MagicsParameter<double> subpage_right_position("subpage_right_position", -1);
static MagicsParameter<double> subpage_y_length_internal("subpage_y_length_internal", -1);
static MagicsParameter<double> subpage_x_length_internal("subpage_x_length_internal", -1);
static MagicsParameter<double> subpage_top_position("subpage_top_position", -1);
static MagicsParameter<string> subpage_clipping("subpage_clipping", "off");
static MagicsParameter<string> subpage_frame("subpage_frame", "on");
static MagicsParameter<int> subpage_frame_thickness("subpage_frame_thickness", 2);
static MagicsParameter<double> subpage_vertical_axis_width("subpage_vertical_axis_width", 1);
static MagicsParameter<double> subpage_horizontal_axis_height("subpage_horizontal_axis_height", 0.5);
static MagicsParameter<string> subpage_map_overlay_control("subpage_map_overlay_control", "basic");
static MagicsParameter<string> subpage_align_horizontal("subpage_align_horizontal", "left");
static MagicsParameter<string> subpage_align_vertical("subpage_align_vertical", "bottom");
static MagicsParameter<string> subpage_map_json_definition("subpage_map_json_definition", "");
static MagicsParameter<string> automatic_title("automatic_title", "off");
static MagicsParameter<string> subpage_expand_mode("subpage_expand_mode", "off");
static MagicsParameter<string> subpage_map_projection("subpage_map_projection", "cylindrical");
static MagicsParameter<string> subpage_background_colour("subpage_background_colour", "none");
static MagicsParameter<string> subpage_frame_colour("subpage_frame_colour", "charcoal");
static MagicsParameter<string> subpage_frame_line_style("subpage_frame_line_style", "solid");
static MagicsParameter<string> subpage_map_preview("subpage_map_preview", "off");
static MagicsParameter<string> subpage_map_magnifier("subpage_map_magnifier", "off");
#include "GeoRectangularProjection.h"
#include "PolarStereographicProjection.h"
#include "Proj4Projection.h"
#include "CartesianTransformation.h"
#include "TaylorProjection.h"
#include "Tephigram.h"
#include "Skewt.h"
#include "Emagram.h"
#include "PreviewVisitor.h"
#include "MagnifierVisitor.h"
static SimpleObjectMaker<GeoRectangularProjection , Transformation> cylindrical_GeoRectangularProjection("cylindrical");
static SimpleObjectMaker<PolarStereographicProjection , Transformation> polar_stereographic_PolarStereographicProjection("polar_stereographic");
static SimpleObjectMaker<Proj4PolarNorth , Transformation> polar_north_Proj4PolarNorth("polar_north");
static SimpleObjectMaker<Proj4PolarSouth , Transformation> polar_south_Proj4PolarSouth("polar_south");
static SimpleObjectMaker<Proj4Geos , Transformation> geos_Proj4Geos("geos");
static SimpleObjectMaker<Proj4Meteosat0 , Transformation> meteosat_Proj4Meteosat0("meteosat");
static SimpleObjectMaker<Proj4Meteosat57 , Transformation> meteosat_57E_Proj4Meteosat57("meteosat_57E");
static SimpleObjectMaker<Proj4Geose , Transformation> goes_east_Proj4Geose("goes_east");
static SimpleObjectMaker<Proj4Lambert , Transformation> lambert_Proj4Lambert("lambert");
static SimpleObjectMaker<Proj4EPSG3857 , Transformation> EPSG_3857_Proj4EPSG3857("EPSG:3857");
static SimpleObjectMaker<Proj4EPSG900913 , Transformation> EPSG_900913_Proj4EPSG900913("EPSG:900913");
static SimpleObjectMaker<Proj4EPSG32661 , Transformation> EPSG_32661_Proj4EPSG32661("EPSG:32661");
static SimpleObjectMaker<Proj4EPSG32761 , Transformation> EPSG_32761_Proj4EPSG32761("EPSG:32761");
static SimpleObjectMaker<Proj4EPSG4326 , Transformation> EPSG_4326_Proj4EPSG4326("EPSG:4326");
static SimpleObjectMaker<Proj4EPSG3035 , Transformation> EPSG_3035_Proj4EPSG3035("EPSG:3035");
static SimpleObjectMaker<Proj4Goode , Transformation> goode_Proj4Goode("goode");
static SimpleObjectMaker<Proj4Collignon , Transformation> collignon_Proj4Collignon("collignon");
static SimpleObjectMaker<Proj4Mollweide , Transformation> mollweide_Proj4Mollweide("mollweide");
static SimpleObjectMaker<Proj4Robinson , Transformation> robinson_Proj4Robinson("robinson");
static SimpleObjectMaker<Proj4Bonne , Transformation> bonne_Proj4Bonne("bonne");
static SimpleObjectMaker<Proj4Google , Transformation> google_Proj4Google("google");
static SimpleObjectMaker<Proj4Efas , Transformation> efas_Proj4Efas("efas");
static SimpleObjectMaker<Proj4TPers , Transformation> tpers_Proj4TPers("tpers");
static SimpleObjectMaker<Proj4Automatic , Transformation> automatic_Proj4Automatic("automatic");
static SimpleObjectMaker<Proj4Mercator , Transformation> mercator_Proj4Mercator("mercator");
static SimpleObjectMaker<CartesianTransformation , Transformation> cartesian_CartesianTransformation("cartesian");
static SimpleObjectMaker<TaylorProjection , Transformation> taylor_TaylorProjection("taylor");
static SimpleObjectMaker<Tephigram , Transformation> tephigram_Tephigram("tephigram");
static SimpleObjectMaker<Skewt , Transformation> skewt_Skewt("skewt");
static SimpleObjectMaker<Emagram , Transformation> emagram_Emagram("emagram");
static SimpleObjectMaker<NoPreviewVisitor , NoPreviewVisitor> off_NoPreviewVisitor("off");
static SimpleObjectMaker<PreviewVisitor , NoPreviewVisitor> on_PreviewVisitor("on");
static SimpleObjectMaker<NoMagnifierVisitor , NoMagnifierVisitor> off_NoMagnifierVisitor("off");
static SimpleObjectMaker<MagnifierVisitor , NoMagnifierVisitor> on_MagnifierVisitor("on");
