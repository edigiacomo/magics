
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ObsPlottingAttributes.h
    \\brief Definition of ObsPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "ObsPlottingAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ObsPlottingAttributes::ObsPlottingAttributes():
	apart_(ParameterManager::getDouble("obs_distance_apart")),
	size_(ParameterManager::getDouble("obs_size")),
	ring_size_(ParameterManager::getDouble("obs_ring_size")),
	present_ww_visible_(ParameterManager::getBool("obs_present_weather")),
	present_ww_colour_(ParameterManager::getString("obs_present_weather_colour")),
	pressure_visible_(ParameterManager::getBool("obs_pressure")),
	upper_air_visible_(ParameterManager::getBool("obs_upper_air_pressure")),
	pressure_tendency_visible_(ParameterManager::getBool("obs_pressure_tendency")),
	station_ring_visible_(ParameterManager::getBool("obs_station_ring")),
	temperature_visible_(ParameterManager::getBool("obs_temperature")),
	thickness_visible_(ParameterManager::getBool("obs_thickness")),
	height_visible_(ParameterManager::getBool("obs_height")),
	identifier_visible_(ParameterManager::getBool("obs_identification")),
	cloud_visible_(ParameterManager::getBool("obs_cloud")),
	low_(ParameterManager::getBool("obs_low_cloud")),
	medium_(ParameterManager::getBool("obs_medium_cloud")),
	high_(ParameterManager::getBool("obs_high_cloud")),
	dewpoint_visible_(ParameterManager::getBool("obs_dewpoint")),
	sea_temperature_visible_(ParameterManager::getBool("obs_sea_temperature")),
	waves_visible_(ParameterManager::getBool("obs_waves")),
	past_ww_visible_(ParameterManager::getBool("obs_past_weather")),
	time_plot_visible_(ParameterManager::getBool("obs_time")),
	visibility_visible_(ParameterManager::getBool("obs_visibility")),
	wind_visible_(ParameterManager::getBool("obs_wind")),
	wind_colour_(ParameterManager::getString("obs_wind_colour")),
	wind_thickness_(ParameterManager::getInt("obs_wind_thickness")),
	wind_projected_(ParameterManager::getBool("obs_wind_projected"))
	,
	colour_(MagTranslator<string, Colour>().magics("obs_colour")),
	pressure_colour_(MagTranslator<string, Colour>().magics("obs_pressure_colour")),
	upper_air_colour_(MagTranslator<string, Colour>().magics("obs_upper_air_pressure_colour")),
	pressure_tendency_colour_(MagTranslator<string, Colour>().magics("obs_pressure_tendency_colour")),
	station_ring_colour_(MagTranslator<string, Colour>().magics("obs_station_ring_colour")),
	temperature_colour_(MagTranslator<string, Colour>().magics("obs_temperature_colour")),
	thickness_colour_(MagTranslator<string, Colour>().magics("obs_thickness_colour")),
	height_colour_(MagTranslator<string, Colour>().magics("obs_height_colour")),
	identifier_colour_(MagTranslator<string, Colour>().magics("obs_identification_colour")),
	low_colour_(MagTranslator<string, Colour>().magics("obs_low_cloud_colour")),
	medium_colour_(MagTranslator<string, Colour>().magics("obs_medium_cloud_colour")),
	high_colour_(MagTranslator<string, Colour>().magics("obs_high_cloud_colour")),
	dewpoint_colour_(MagTranslator<string, Colour>().magics("obs_dewpoint_colour")),
	sea_temperature_colour_(MagTranslator<string, Colour>().magics("obs_sea_temperature_colour")),
	waves_colour_(MagTranslator<string, Colour>().magics("obs_waves_colour")),
	past_ww_colour_(MagTranslator<string, Colour>().magics("obs_past_weather_colour")),
	time_plot_colour_(MagTranslator<string, Colour>().magics("obs_time_colour")),
	visibility_colour_(MagTranslator<string, Colour>().magics("obs_visibility_colour"))
	
{
}


ObsPlottingAttributes::~ObsPlottingAttributes()
{

}


void ObsPlottingAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "obs";
	
	setAttribute(prefix, "obs_distance_apart", apart_, params);
	setAttribute(prefix, "obs_size", size_, params);
	setAttribute(prefix, "obs_ring_size", ring_size_, params);
	setAttribute(prefix, "obs_present_weather", present_ww_visible_, params);
	setAttribute(prefix, "obs_present_weather_colour", present_ww_colour_, params);
	setAttribute(prefix, "obs_pressure", pressure_visible_, params);
	setAttribute(prefix, "obs_upper_air_pressure", upper_air_visible_, params);
	setAttribute(prefix, "obs_pressure_tendency", pressure_tendency_visible_, params);
	setAttribute(prefix, "obs_station_ring", station_ring_visible_, params);
	setAttribute(prefix, "obs_temperature", temperature_visible_, params);
	setAttribute(prefix, "obs_thickness", thickness_visible_, params);
	setAttribute(prefix, "obs_height", height_visible_, params);
	setAttribute(prefix, "obs_identification", identifier_visible_, params);
	setAttribute(prefix, "obs_cloud", cloud_visible_, params);
	setAttribute(prefix, "obs_low_cloud", low_, params);
	setAttribute(prefix, "obs_medium_cloud", medium_, params);
	setAttribute(prefix, "obs_high_cloud", high_, params);
	setAttribute(prefix, "obs_dewpoint", dewpoint_visible_, params);
	setAttribute(prefix, "obs_sea_temperature", sea_temperature_visible_, params);
	setAttribute(prefix, "obs_waves", waves_visible_, params);
	setAttribute(prefix, "obs_past_weather", past_ww_visible_, params);
	setAttribute(prefix, "obs_time", time_plot_visible_, params);
	setAttribute(prefix, "obs_visibility", visibility_visible_, params);
	setAttribute(prefix, "obs_wind", wind_visible_, params);
	setAttribute(prefix, "obs_wind_colour", wind_colour_, params);
	setAttribute(prefix, "obs_wind_thickness", wind_thickness_, params);
	setAttribute(prefix, "obs_wind_projected", wind_projected_, params);
	
	setMember(prefix, "obs_colour", colour_, params);
	setMember(prefix, "obs_pressure_colour", pressure_colour_, params);
	setMember(prefix, "obs_upper_air_pressure_colour", upper_air_colour_, params);
	setMember(prefix, "obs_pressure_tendency_colour", pressure_tendency_colour_, params);
	setMember(prefix, "obs_station_ring_colour", station_ring_colour_, params);
	setMember(prefix, "obs_temperature_colour", temperature_colour_, params);
	setMember(prefix, "obs_thickness_colour", thickness_colour_, params);
	setMember(prefix, "obs_height_colour", height_colour_, params);
	setMember(prefix, "obs_identification_colour", identifier_colour_, params);
	setMember(prefix, "obs_low_cloud_colour", low_colour_, params);
	setMember(prefix, "obs_medium_cloud_colour", medium_colour_, params);
	setMember(prefix, "obs_high_cloud_colour", high_colour_, params);
	setMember(prefix, "obs_dewpoint_colour", dewpoint_colour_, params);
	setMember(prefix, "obs_sea_temperature_colour", sea_temperature_colour_, params);
	setMember(prefix, "obs_waves_colour", waves_colour_, params);
	setMember(prefix, "obs_past_weather_colour", past_ww_colour_, params);
	setMember(prefix, "obs_time_colour", time_plot_colour_, params);
	setMember(prefix, "obs_visibility_colour", visibility_colour_, params);
	
}

void ObsPlottingAttributes::copy(const ObsPlottingAttributes& other)
{
	apart_ = other.apart_;
	size_ = other.size_;
	ring_size_ = other.ring_size_;
	present_ww_visible_ = other.present_ww_visible_;
	present_ww_colour_ = other.present_ww_colour_;
	pressure_visible_ = other.pressure_visible_;
	upper_air_visible_ = other.upper_air_visible_;
	pressure_tendency_visible_ = other.pressure_tendency_visible_;
	station_ring_visible_ = other.station_ring_visible_;
	temperature_visible_ = other.temperature_visible_;
	thickness_visible_ = other.thickness_visible_;
	height_visible_ = other.height_visible_;
	identifier_visible_ = other.identifier_visible_;
	cloud_visible_ = other.cloud_visible_;
	low_ = other.low_;
	medium_ = other.medium_;
	high_ = other.high_;
	dewpoint_visible_ = other.dewpoint_visible_;
	sea_temperature_visible_ = other.sea_temperature_visible_;
	waves_visible_ = other.waves_visible_;
	past_ww_visible_ = other.past_ww_visible_;
	time_plot_visible_ = other.time_plot_visible_;
	visibility_visible_ = other.visibility_visible_;
	wind_visible_ = other.wind_visible_;
	wind_colour_ = other.wind_colour_;
	wind_thickness_ = other.wind_thickness_;
	wind_projected_ = other.wind_projected_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	pressure_colour_ = unique_ptr<Colour>(other.pressure_colour_->clone());
	upper_air_colour_ = unique_ptr<Colour>(other.upper_air_colour_->clone());
	pressure_tendency_colour_ = unique_ptr<Colour>(other.pressure_tendency_colour_->clone());
	station_ring_colour_ = unique_ptr<Colour>(other.station_ring_colour_->clone());
	temperature_colour_ = unique_ptr<Colour>(other.temperature_colour_->clone());
	thickness_colour_ = unique_ptr<Colour>(other.thickness_colour_->clone());
	height_colour_ = unique_ptr<Colour>(other.height_colour_->clone());
	identifier_colour_ = unique_ptr<Colour>(other.identifier_colour_->clone());
	low_colour_ = unique_ptr<Colour>(other.low_colour_->clone());
	medium_colour_ = unique_ptr<Colour>(other.medium_colour_->clone());
	high_colour_ = unique_ptr<Colour>(other.high_colour_->clone());
	dewpoint_colour_ = unique_ptr<Colour>(other.dewpoint_colour_->clone());
	sea_temperature_colour_ = unique_ptr<Colour>(other.sea_temperature_colour_->clone());
	waves_colour_ = unique_ptr<Colour>(other.waves_colour_->clone());
	past_ww_colour_ = unique_ptr<Colour>(other.past_ww_colour_->clone());
	time_plot_colour_ = unique_ptr<Colour>(other.time_plot_colour_->clone());
	visibility_colour_ = unique_ptr<Colour>(other.visibility_colour_->clone());
	
}


bool ObsPlottingAttributes::accept(const string& node)
{

	if ( magCompare(node, "obs")  )
		return true;
	
	return false;
}

void ObsPlottingAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "obs")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ObsPlottingAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " apart = " <<  apart_;
	out << " size = " <<  size_;
	out << " ring_size = " <<  ring_size_;
	out << " present_ww_visible = " <<  present_ww_visible_;
	out << " present_ww_colour = " <<  present_ww_colour_;
	out << " pressure_visible = " <<  pressure_visible_;
	out << " upper_air_visible = " <<  upper_air_visible_;
	out << " pressure_tendency_visible = " <<  pressure_tendency_visible_;
	out << " station_ring_visible = " <<  station_ring_visible_;
	out << " temperature_visible = " <<  temperature_visible_;
	out << " thickness_visible = " <<  thickness_visible_;
	out << " height_visible = " <<  height_visible_;
	out << " identifier_visible = " <<  identifier_visible_;
	out << " cloud_visible = " <<  cloud_visible_;
	out << " low = " <<  low_;
	out << " medium = " <<  medium_;
	out << " high = " <<  high_;
	out << " dewpoint_visible = " <<  dewpoint_visible_;
	out << " sea_temperature_visible = " <<  sea_temperature_visible_;
	out << " waves_visible = " <<  waves_visible_;
	out << " past_ww_visible = " <<  past_ww_visible_;
	out << " time_plot_visible = " <<  time_plot_visible_;
	out << " visibility_visible = " <<  visibility_visible_;
	out << " wind_visible = " <<  wind_visible_;
	out << " wind_colour = " <<  wind_colour_;
	out << " wind_thickness = " <<  wind_thickness_;
	out << " wind_projected = " <<  wind_projected_;
	out << " colour = " <<  *colour_;
	out << " pressure_colour = " <<  *pressure_colour_;
	out << " upper_air_colour = " <<  *upper_air_colour_;
	out << " pressure_tendency_colour = " <<  *pressure_tendency_colour_;
	out << " station_ring_colour = " <<  *station_ring_colour_;
	out << " temperature_colour = " <<  *temperature_colour_;
	out << " thickness_colour = " <<  *thickness_colour_;
	out << " height_colour = " <<  *height_colour_;
	out << " identifier_colour = " <<  *identifier_colour_;
	out << " low_colour = " <<  *low_colour_;
	out << " medium_colour = " <<  *medium_colour_;
	out << " high_colour = " <<  *high_colour_;
	out << " dewpoint_colour = " <<  *dewpoint_colour_;
	out << " sea_temperature_colour = " <<  *sea_temperature_colour_;
	out << " waves_colour = " <<  *waves_colour_;
	out << " past_ww_colour = " <<  *past_ww_colour_;
	out << " time_plot_colour = " <<  *time_plot_colour_;
	out << " visibility_colour = " <<  *visibility_colour_;
	
	out << "]" << "\n";
}

void ObsPlottingAttributes::toxml(ostream& out)  const
{
	out <<  "\"obs\"";
	out << ", \"obs_distance_apart\":";
	niceprint(out,apart_);
	out << ", \"obs_size\":";
	niceprint(out,size_);
	out << ", \"obs_ring_size\":";
	niceprint(out,ring_size_);
	out << ", \"obs_present_weather\":";
	niceprint(out,present_ww_visible_);
	out << ", \"obs_present_weather_colour\":";
	niceprint(out,present_ww_colour_);
	out << ", \"obs_pressure\":";
	niceprint(out,pressure_visible_);
	out << ", \"obs_upper_air_pressure\":";
	niceprint(out,upper_air_visible_);
	out << ", \"obs_pressure_tendency\":";
	niceprint(out,pressure_tendency_visible_);
	out << ", \"obs_station_ring\":";
	niceprint(out,station_ring_visible_);
	out << ", \"obs_temperature\":";
	niceprint(out,temperature_visible_);
	out << ", \"obs_thickness\":";
	niceprint(out,thickness_visible_);
	out << ", \"obs_height\":";
	niceprint(out,height_visible_);
	out << ", \"obs_identification\":";
	niceprint(out,identifier_visible_);
	out << ", \"obs_cloud\":";
	niceprint(out,cloud_visible_);
	out << ", \"obs_low_cloud\":";
	niceprint(out,low_);
	out << ", \"obs_medium_cloud\":";
	niceprint(out,medium_);
	out << ", \"obs_high_cloud\":";
	niceprint(out,high_);
	out << ", \"obs_dewpoint\":";
	niceprint(out,dewpoint_visible_);
	out << ", \"obs_sea_temperature\":";
	niceprint(out,sea_temperature_visible_);
	out << ", \"obs_waves\":";
	niceprint(out,waves_visible_);
	out << ", \"obs_past_weather\":";
	niceprint(out,past_ww_visible_);
	out << ", \"obs_time\":";
	niceprint(out,time_plot_visible_);
	out << ", \"obs_visibility\":";
	niceprint(out,visibility_visible_);
	out << ", \"obs_wind\":";
	niceprint(out,wind_visible_);
	out << ", \"obs_wind_colour\":";
	niceprint(out,wind_colour_);
	out << ", \"obs_wind_thickness\":";
	niceprint(out,wind_thickness_);
	out << ", \"obs_wind_projected\":";
	niceprint(out,wind_projected_);
	out << ", \"obs_colour\":";
	niceprint(out, *colour_);
	out << ", \"obs_pressure_colour\":";
	niceprint(out, *pressure_colour_);
	out << ", \"obs_upper_air_pressure_colour\":";
	niceprint(out, *upper_air_colour_);
	out << ", \"obs_pressure_tendency_colour\":";
	niceprint(out, *pressure_tendency_colour_);
	out << ", \"obs_station_ring_colour\":";
	niceprint(out, *station_ring_colour_);
	out << ", \"obs_temperature_colour\":";
	niceprint(out, *temperature_colour_);
	out << ", \"obs_thickness_colour\":";
	niceprint(out, *thickness_colour_);
	out << ", \"obs_height_colour\":";
	niceprint(out, *height_colour_);
	out << ", \"obs_identification_colour\":";
	niceprint(out, *identifier_colour_);
	out << ", \"obs_low_cloud_colour\":";
	niceprint(out, *low_colour_);
	out << ", \"obs_medium_cloud_colour\":";
	niceprint(out, *medium_colour_);
	out << ", \"obs_high_cloud_colour\":";
	niceprint(out, *high_colour_);
	out << ", \"obs_dewpoint_colour\":";
	niceprint(out, *dewpoint_colour_);
	out << ", \"obs_sea_temperature_colour\":";
	niceprint(out, *sea_temperature_colour_);
	out << ", \"obs_waves_colour\":";
	niceprint(out, *waves_colour_);
	out << ", \"obs_past_weather_colour\":";
	niceprint(out, *past_ww_colour_);
	out << ", \"obs_time_colour\":";
	niceprint(out, *time_plot_colour_);
	out << ", \"obs_visibility_colour\":";
	niceprint(out, *visibility_colour_);
	
}

static MagicsParameter<double> obs_distance_apart("obs_distance_apart", 1.0);
static MagicsParameter<double> obs_size("obs_size", 0.25);
static MagicsParameter<double> obs_ring_size("obs_ring_size", -1);
static MagicsParameter<string> obs_present_weather("obs_present_weather", "on");
static MagicsParameter<string> obs_present_weather_colour("obs_present_weather_colour", "automatic");
static MagicsParameter<string> obs_pressure("obs_pressure", "on");
static MagicsParameter<string> obs_upper_air_pressure("obs_upper_air_pressure", "off");
static MagicsParameter<string> obs_pressure_tendency("obs_pressure_tendency", "on");
static MagicsParameter<string> obs_station_ring("obs_station_ring", "on");
static MagicsParameter<string> obs_temperature("obs_temperature", "on");
static MagicsParameter<string> obs_thickness("obs_thickness", "on");
static MagicsParameter<string> obs_height("obs_height", "on");
static MagicsParameter<string> obs_identification("obs_identification", "off");
static MagicsParameter<string> obs_cloud("obs_cloud", "on");
static MagicsParameter<string> obs_low_cloud("obs_low_cloud", "on");
static MagicsParameter<string> obs_medium_cloud("obs_medium_cloud", "on");
static MagicsParameter<string> obs_high_cloud("obs_high_cloud", "on");
static MagicsParameter<string> obs_dewpoint("obs_dewpoint", "on");
static MagicsParameter<string> obs_sea_temperature("obs_sea_temperature", "on");
static MagicsParameter<string> obs_waves("obs_waves", "on");
static MagicsParameter<string> obs_past_weather("obs_past_weather", "on");
static MagicsParameter<string> obs_time("obs_time", "off");
static MagicsParameter<string> obs_visibility("obs_visibility", "on");
static MagicsParameter<string> obs_wind("obs_wind", "on");
static MagicsParameter<string> obs_wind_colour("obs_wind_colour", "automatic");
static MagicsParameter<int> obs_wind_thickness("obs_wind_thickness", 1);
static MagicsParameter<string> obs_wind_projected("obs_wind_projected", "on");
static MagicsParameter<string> obs_colour("obs_colour", "black");
static MagicsParameter<string> obs_pressure_colour("obs_pressure_colour", "automatic");
static MagicsParameter<string> obs_upper_air_pressure_colour("obs_upper_air_pressure_colour", "automatic");
static MagicsParameter<string> obs_pressure_tendency_colour("obs_pressure_tendency_colour", "red");
static MagicsParameter<string> obs_station_ring_colour("obs_station_ring_colour", "automatic");
static MagicsParameter<string> obs_temperature_colour("obs_temperature_colour", "automatic");
static MagicsParameter<string> obs_thickness_colour("obs_thickness_colour", "automatic");
static MagicsParameter<string> obs_height_colour("obs_height_colour", "automatic");
static MagicsParameter<string> obs_identification_colour("obs_identification_colour", "automatic");
static MagicsParameter<string> obs_low_cloud_colour("obs_low_cloud_colour", "automatic");
static MagicsParameter<string> obs_medium_cloud_colour("obs_medium_cloud_colour", "automatic");
static MagicsParameter<string> obs_high_cloud_colour("obs_high_cloud_colour", "red");
static MagicsParameter<string> obs_dewpoint_colour("obs_dewpoint_colour", "red");
static MagicsParameter<string> obs_sea_temperature_colour("obs_sea_temperature_colour", "black");
static MagicsParameter<string> obs_waves_colour("obs_waves_colour", "black");
static MagicsParameter<string> obs_past_weather_colour("obs_past_weather_colour", "red");
static MagicsParameter<string> obs_time_colour("obs_time_colour", "automatic");
static MagicsParameter<string> obs_visibility_colour("obs_visibility_colour", "automatic");
