/*
  Copyright (c) 2020, Robin Zimmeck <robin@robin-zimmeck.de>
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  
  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
  
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
  
  3. Neither the name of the copyright holder nor the names of its contributors
     may be used to endorse or promote products derived from this software
     without specific prior written permission.
  
  This software is provided by the copyright holders and contributors "as is"
  and any express or implied warranties, including, but not limited to, the
  implied warranties of merchantability and fitness for a particular purpose are
  disclaimed. In no event shall the copyright holder or contributors be liable
  for any direct, indirect, incidental, special, exemplary, or consequential
  damages (including, but not limited to, procurement of substitute goods or
  services; loss of use, data, or profits; or business interruption) however
  caused and on any theory of liability, whether in contract, strict liability,
  or tort (including negligence or otherwise) arising in any way out of the use
  of this software, even if advised of the possibility of such damage.
*/


#pragma once

#include "forward.h"
#include "unit.h"
#include "quantity.h"

namespace minisi
{

//                                       T   L   M   I   Th  N   J
// base units
using second_t                 = unit_t< 1,  0,  0,  0,  0,  0,  0>;
using metre_t                  = unit_t< 0,  1,  0,  0,  0,  0,  0>;
using kilogram_t               = unit_t< 0,  0,  1,  0,  0,  0,  0>;
using ampere_t                 = unit_t< 0,  0,  0,  1,  0,  0,  0>;
using kelvin_t                 = unit_t< 0,  0,  0,  0,  1,  0,  0>;
using mole_t                   = unit_t< 0,  0,  0,  0,  0,  1,  0>;
using candela_t                = unit_t< 0,  0,  0,  0,  0,  0,  1>;

// derived units
using hertz_t                  = unit_t<-1,  0,  0,  0,  0,  0,  0>;
using newton_t                 = unit_t<-2,  1,  1,  0,  0,  0,  0>;
using pascal_t                 = unit_t<-2, -1,  1,  0,  0,  0,  0>;
using joule_t                  = unit_t<-2,  2,  1,  0,  0,  0,  0>;
using watt_t                   = unit_t<-3,  2,  1,  0,  0,  0,  0>;
using coulomb_t                = unit_t< 1,  0,  0,  1,  0,  0,  0>;
using volt_t                   = unit_t<-3,  2,  1, -1,  0,  0,  0>;
using farad_t                  = unit_t< 4, -2, -1,  2,  0,  0,  0>;
using ohm_t                    = unit_t<-3,  2,  1, -2,  0,  0,  0>;
using siemens_t                = unit_t< 3, -2, -1,  2,  0,  0,  0>;
using weber_t                  = unit_t<-2,  2,  1, -1,  0,  0,  0>;
using tesla_t                  = unit_t<-2,  0,  1, -1,  0,  0,  0>;
using henry_t                  = unit_t<-2,  2,  1, -2,  0,  0,  0>;
using lumen_t                  = unit_t< 0,  0,  0,  0,  0,  0,  1>;
using lux_t                    = unit_t< 0, -2,  0,  0,  0,  0,  1>;
using becquerel_t              = unit_t<-1,  0,  0,  0,  0,  0,  0>;
using gray_t                   = unit_t<-2,  2,  0,  0,  0,  0,  0>;
using sievert_t                = unit_t<-2,  2,  0,  0,  0,  0,  0>;
using katal_t                  = unit_t<-1,  0,  0,  0,  0,  1,  0>;

// additional units
using squareMetre_t            = unit_t< 0,  2,  0,  0,  0,  0,  0>;
using cubicMetre_t             = unit_t< 0,  3,  0,  0,  0,  0,  0>;
using metrePerSecond_t         = unit_t<-1,  1,  0,  0,  0,  0,  0>;
using metrePerSecondSquared_t  = unit_t<-2,  1,  0,  0,  0,  0,  0>;
using metrePerSecondCubed_t    = unit_t<-3,  1,  0,  0,  0,  0,  0>;

using kilogramPerCubicMetre_t  = unit_t< 0, -3,  1,  0,  0,  0,  0>;
using kilogramPerSquareMetre_t = unit_t< 0, -2,  1,  0,  0,  0,  0>;
using kilogramPerMetre_t       = unit_t< 0, -1,  1,  0,  0,  0,  0>;
using cubicMetrePerKilogram_t  = unit_t< 0,  3, -1,  0,  0,  0,  0>;
using amperePerSquareMetre_t   = unit_t< 0, -2,  0,  1,  0,  0,  0>;
using amperePerMetre_t         = unit_t< 0, -1,  0,  1,  0,  0,  0>;
using molePerCubicMetre_t      = unit_t< 0, -3,  0,  0,  0,  1,  0>;
using candelaPerSquareMetre_t  = unit_t< 0, -2,  0,  0,  0,  0,  1>;



// base quantities
using duration_t        = quantity_t<second_t>;
using length_t          = quantity_t<metre_t>;
using mass_t            = quantity_t<kilogram_t>;
using current_t         = quantity_t<ampere_t>;
using temperature_t     = quantity_t<kelvin_t>;
using amount_t          = quantity_t<mole_t>;
using intensity_t       = quantity_t<candela_t>;

// derived quantites
using frequency_t           = quantity_t<hertz_t>;
using force_t               = quantity_t<newton_t>;
using pressure_t            = quantity_t<pascal_t>;
using energy_t              = quantity_t<joule_t>;
using power_t               = quantity_t<watt_t>;
using charge_t              = quantity_t<coulomb_t>;
using voltage_t             = quantity_t<volt_t>;
using capacitance_t         = quantity_t<farad_t>;
using resistance_t          = quantity_t<ohm_t>;
using conductance_t         = quantity_t<siemens_t>;
using magneticFlux_t        = quantity_t<weber_t>;
using magneticFluxDensity_t = quantity_t<tesla_t>;
using inductance_t          = quantity_t<henry_t>;
using luminousFlux_t        = quantity_t<lumen_t>;
using illuminance_t         = quantity_t<lux_t>;
using radioactivity_t       = quantity_t<becquerel_t>;
using absorbedDose_t        = quantity_t<gray_t>;
using equivalentDose_t      = quantity_t<sievert_t>;
using catalyticActivity_t   = quantity_t<katal_t>;

// additional units
using area_t            = quantity_t<squareMetre_t>;
using volume_t          = quantity_t<cubicMetre_t>;
using velocity_t        = quantity_t<metrePerSecond_t>;
using acceleration_t    = quantity_t<metrePerSecondSquared_t>;
using jolt_t            = quantity_t<metrePerSecondCubed_t>;
using massPerLength_t   = quantity_t<kilogramPerMetre_t>;

// $TODO complete

static const auto dimensionless = dimensionless_t::from_value( 1.0 );

// base units
static const auto second = duration_t::from_value( 1.0 );
static const auto metre = length_t::from_value( 1.0 );
static const auto kilogram = mass_t::from_value( 1.0 );
static const auto ampere = current_t::from_value( 1.0 );
static const auto kelvin = temperature_t::from_value( 1.0 );
static const auto mole = amount_t::from_value( 1.0 );
static const auto candela = intensity_t::from_value( 1.0 );

// derived units
static const auto hertz = frequency_t::from_value( 1.0 );
static const auto newton = force_t::from_value( 1.0 );
static const auto pascal = pressure_t::from_value( 1.0 );
static const auto joule = energy_t::from_value( 1.0 );
static const auto watt = power_t::from_value( 1.0 );
static const auto coulomb = charge_t::from_value( 1.0 );
static const auto volt = voltage_t::from_value( 1.0 );
static const auto farad = capacitance_t::from_value( 1.0 );
static const auto ohm = resistance_t::from_value( 1.0 );
static const auto siemens = conductance_t::from_value( 1.0 );
static const auto weber = magneticFlux_t::from_value( 1.0 );
static const auto tesla = magneticFluxDensity_t::from_value( 1.0 );
static const auto henry = inductance_t::from_value( 1.0 );
static const auto lumen = luminousFlux_t::from_value( 1.0 );
static const auto lux = illuminance_t::from_value( 1.0 );
static const auto becquerel = radioactivity_t::from_value( 1.0 );
static const auto gray = absorbedDose_t::from_value( 1.0 );
static const auto sievert = equivalentDose_t::from_value( 1.0 );
static const auto katal = catalyticActivity_t::from_value( 1.0 );

static const auto kilometre = length_t::from_value( 1000.0 );
static const auto minute = duration_t::from_value( 60.0 );
static const auto hour = duration_t::from_value( 3600.0 );
static const auto ton = mass_t::from_value(1000.0);
}
