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

#include "minisi/minisi.h"

namespace minisi::literals
{

inline
length_t
operator"" _m(long double value)
{
  return double( value ) * metre;
}

inline
area_t
operator"" _m²(long double value)
{
  return double( value ) * metre * metre;
}
inline
duration_t
operator"" _s(long double value)
{
  return double( value ) * second;
}

inline
mass_t
operator"" _kg(long double value)
{
  return double( value ) * kilogram;
}

inline
force_t
operator"" _N(long double value)
{
  return double( value ) * newton;
}

inline
energy_t
operator"" _J(long double value)
{
  return double( value ) * joule;
}

inline
power_t
operator"" _W(long double value)
{
  return double( value ) * watt;
}

inline
velocity_t
operator"" _mps(long double value)
{
  return double( value ) * metre / second;
}

inline
acceleration_t
operator"" _mps2(long double value)
{
  return double( value ) * metre / (second * second);
}

inline
acceleration_t
operator"" _mps²(long double value)
{
  return double( value ) * metre / (second * second);
}

inline
jolt_t
operator"" _mps3(long double value)
{
  return double( value ) * metre / (second * second * second);
}

inline
jolt_t
operator"" _mps³(long double value)
{
  return double( value ) * metre / (second * second * second);
}

inline
velocity_t
operator"" _kmph(long double value)
{
  return double( value ) * kilometre / hour;
}

inline
mass_t
operator"" _t(long double value)
{
  return double(value) * ton;
}

}

// $TODO complete
