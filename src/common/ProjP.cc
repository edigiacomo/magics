/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

//! \file ProjP.cc
/*!
 Sylvie Lamy-Thepaut - ECMWF Apr 02

 Changes:

   Apr 06: update for GCC 4.0 (Stephan)
*/
#include "ProjP.h"
#include "MagException.h"


#include <proj.h>

using namespace magics;

static PJ_CONTEXT* context_ = 0;

ProjP::ProjP() : converter_(0) {}
ProjP::ProjP(const string& from, const string& to) : from_(from), to_(to), converter_(0) {
    if (!context_)
        context_ = proj_context_create();
    PJ* p = proj_create_crs_to_crs(context_, from_.c_str(), to_.c_str(), NULL);
    if(!p) {
        std::stringstream oss;
        oss << "ProjP: cannot create crs to crs from [" << from_ << "] to [" << to_ << "]";
        throw MagicsException(oss.str());
    }
    converter_ = proj_normalize_for_visualization(context_, p);

    ASSERT(converter_);
    // double x = -180;
    // double y = 90;
    // convert(x, y);
    // revert(x, y);
}

ProjP::~ProjP() {
    if (converter_)
        proj_destroy(converter_);

    converter_ = 0;
}


string ProjP::error(int error) {
    return proj_errno_string(error);
}


int LatLonProjP::convert(double& x, double& y) const {
    PJ_COORD in, out;
    in.lpzt.lam = x;
    in.lpzt.phi = y;
    in.lpzt.z   = 0.0;
    in.lpzt.t   = HUGE_VAL;

    out = proj_trans(converter_, PJ_FWD, in);
    if (proj_errno(converter_)) {
        proj_errno_reset(converter_);
        return 1;
    }
    x = out.xy.x;
    y = out.xy.y;
    return 0;
}
int LatLonProjP::revert(double& x, double& y) const {
    PJ_COORD in, out;
    in.xyzt.x = x;
    in.xyzt.y = y;
    in.xyzt.z = 0;
    in.xyzt.t = 0;


    out = proj_trans(converter_, PJ_INV, in);
    if (proj_errno(converter_)) {
        proj_errno_reset(converter_);
        return 1;
    }

    x = out.lpzt.lam;
    y = out.lpzt.phi;
    return 0;
}

int ProjP::convert(double& x, double& y) const {
    PJ_COORD in, out;

    in.xyzt.x = x;
    in.xyzt.y = y;
    in.xyzt.z = 0;
    in.xyzt.t = 0;
    out     = proj_trans(converter_, PJ_FWD, in);
    if (proj_errno(converter_)) {
        proj_errno_reset(converter_);
        return 1;
    }
    x = out.xy.x;
    y = out.xy.y;

    return 0;
}
int ProjP::revert(double& x, double& y) const {
    PJ_COORD in, out;
    in.xyzt.x = x;
    in.xyzt.y = y;
    in.xyzt.z = 0;
    in.xyzt.t = 0;

    out = proj_trans(converter_, PJ_INV, in);
    if (proj_errno(converter_)) {
        proj_errno_reset(converter_);
        return 1;
    }
    x = out.xy.x;
    y = out.xy.y;



    return 0;
}

void ProjP::print(ostream&) const {}
