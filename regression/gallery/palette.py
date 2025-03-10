# (C) Copyright 1996-2016 ECMWF.
# 
# This software is licensed under the terms of the Apache Licence Version 2.0
# which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
# In applying this licence, ECMWF does not waive the privileges and immunities 
# granted to it by virtue of its status as an intergovernmental organisation nor
# does it submit to any jurisdiction.

from Magics.macro import *

#Loading GRIB file
data = mgrib(grib_input_file_name='2t.grib',grib_field_position=1)

#Setting output
output = output(
	output_formats                = ['png'],
	output_name                   = 'palette',
	output_name_first_page_number = 'off')

#Setting the geographical area
area = mmap(
	subpage_lower_left_latitude    = 34.5,
	subpage_lower_left_longitude   = -10.67,
	subpage_map_projection         = 'cylindrical',
	subpage_upper_right_latitude   = 71.05,
	subpage_upper_right_longitude  = 31.55,
)    

#Setting the coastlines
background = mcoast(
	map_coastline_land_shade        = 'on',
    map_coastline_land_shade_colour = 'cream')

foreground = mcoast(
	map_coastline_land_shade        = 'off',
	map_grid_line_style             = 'dash',
	map_grid_colour                 = 'grey',
	map_label                       = 'on',
	map_coastline_colour            = 'black')

#Defining the contour
contour = mcont(
	contour                        = 'off',
	contour_highlight_frequency    = 100,
	contour_highlight_thickness    = 5,
	contour_hilo                   = 'off',
	contour_interval               = 2.0,
	contour_label                  = 'off',
	contour_level_selection_type   = 'interval',
	contour_line_thickness         = 3,
	contour_shade                  = 'on',
	contour_shade_palette_name     = 'eccharts_blue_brown_12', 
	contour_shade_colour_method    = 'palette',
	contour_shade_max_level        = 42.0,
	contour_shade_method           = 'area_fill',
	contour_shade_min_level        = -32.0,
	legend                         = 'on',
)

#Picking the grib metadata
title = mtext(
    text_lines                     = ['<font size="1">2m temperature (Range: -32 .. 42)</font>','<magics_title/>'],
    text_justification             = 'left',
    text_font_size                 = 0.6,
    text_colour                    = 'charcoal')     

#Plotting
plot(output,area,background,data,title,contour,foreground)

#For documentation only
tofortran('contour9',output,area,data,background,contour,foreground,title)
tomv4('contour9',contour)
tohtml('contour9',data,contour)
