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

#include "minisi.h"

#include <iostream>

namespace minisi
{

namespace detail
{

inline
const char *
get_superscript(const char *c)
{
  if (!c)
  {
    return c;
  }

  switch (*c)
  {
    case '-': return "⁻";
    case '/': return "⸍";
    case '0': return "⁰";
    case '1': return "¹";
    case '2': return "²";
    case '3': return "³";
    case '4': return "⁴";
    case '5': return "⁵";
    case '6': return "⁶";
    case '7': return "⁷";
    case '8': return "⁸";
    case '9': return "⁹";
    default:  return c;
  }
}

inline
void
write_superscript(std::ostream &out,
                  int value)
{
  const auto str = std::to_string(value);
  for (const auto &c : str)
  {
    out << get_superscript(&c);
  }
}

inline
bool
write_unit(std::ostream &out,
           const char *symbol,
           int num,
           int den,
           bool first)
{
  if (num == 0)
  {
    return first;
  }

  if (!first)
  {
    out << "·";
  }

  out << symbol;

  if (num == 1 && den == 1)
  {
    return false;
  }

  write_superscript(out, num);

  if (den != 1)
  {
    out << get_superscript("/");
    write_superscript(out, den);
  }

  return false;
}

} // namespace detail

template<int TimeNum,
         int LengthNum,
         int MassNum,
         int CurrentNum,
         int TemperatureNum,
         int AmountNum,
         int IntensityNum,
         int TimeDen,
         int LengthDen,
         int MassDen,
         int CurrentDen,
         int TemperatureDen,
         int AmountDen,
         int IntensityDen>
std::ostream &
operator<<(std::ostream &out, unit_t<TimeNum,
                                     LengthNum,
                                     MassNum,
                                     CurrentNum,
                                     TemperatureNum,
                                     AmountNum,
                                     IntensityNum,
                                     TimeDen,
                                     LengthDen,
                                     MassDen,
                                     CurrentDen,
                                     TemperatureDen,
                                     AmountDen,
                                     IntensityDen>)
{
  using argUnit_t = unit_t<TimeNum,
                           LengthNum,
                           MassNum,
                           CurrentNum,
                           TemperatureNum,
                           AmountNum,
                           IntensityNum,
                           TimeDen,
                           LengthDen,
                           MassDen,
                           CurrentDen,
                           TemperatureDen,
                           AmountDen,
                           IntensityDen>;

  if (std::is_same<argUnit_t, dimensionlessUnit_t>::value) { out << "[1]"; }
  else if (std::is_same<argUnit_t, second_t>::value) { out << "s"; }
  else if (std::is_same<argUnit_t, metre_t>::value) { out << "m"; }
  else if (std::is_same<argUnit_t, kilogram_t>::value) { out << "kg"; }
  else if (std::is_same<argUnit_t, ampere_t>::value) { out << "A"; }
  else if (std::is_same<argUnit_t, kelvin_t>::value) { out << "K"; }
  else if (std::is_same<argUnit_t, mole_t>::value) { out << "mol"; }
  else if (std::is_same<argUnit_t, candela_t>::value) { out << "cd"; }
  else if (std::is_same<argUnit_t, newton_t>::value) { out << "N"; }
  else if (std::is_same<argUnit_t, joule_t>::value) { out << "J"; }
  else if (std::is_same<argUnit_t, watt_t>::value) { out << "W"; }
  else if (std::is_same<argUnit_t, metrePerSecond_t>::value) { out << "m/s"; }
  else if (std::is_same<argUnit_t, metrePerSecondSquared_t>::value) { out << "m/s²"; }
  else if (std::is_same<argUnit_t, metrePerSecondCubed_t>::value) { out << "m/s³"; }
  else
  {
    bool first = true;
    first = detail::write_unit(out, "s", TimeNum, TimeDen, first);
    first = detail::write_unit(out, "m", LengthNum, LengthDen, first);
    first = detail::write_unit(out, "kg", MassNum, MassDen, first);
    first = detail::write_unit(out, "A", CurrentNum, CurrentDen, first);
    first = detail::write_unit(out, "K", TemperatureNum, TemperatureDen, first);
    first = detail::write_unit(out, "mol", AmountNum, AmountDen, first);
    first = detail::write_unit(out, "cd", IntensityNum, IntensityDen, first);
  }

  return out;
}

template<typename Unit>
std::ostream &
operator<<(std::ostream &out, quantity_t<Unit> quantity)
{
  out << quantity.value() << ' ' << Unit{};
  return out;
}

}
