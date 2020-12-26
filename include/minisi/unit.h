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

#include <ratio>

namespace minisi
{

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
struct unit_t
{
  using Time = std::ratio<TimeNum, TimeDen>;
  using Length = std::ratio<LengthNum, LengthDen>;
  using Mass = std::ratio<MassNum, MassDen>;
  using Current = std::ratio<CurrentNum, CurrentDen>;
  using Temperature = std::ratio<TemperatureNum, TemperatureDen>;
  using Amount = std::ratio<AmountNum, AmountDen>;
  using Intensity = std::ratio<IntensityNum, IntensityDen>;
};

using dimensionlessUnit_t = unit_t<>;

namespace detail
{

template<typename Lhs, typename Rhs>
struct unit_pow_calc_t
{
  using Time = std::ratio_multiply<typename Lhs::Time, typename Rhs::Time>;
  using Length = std::ratio_multiply<typename Lhs::Length, typename Rhs::Length>;
  using Mass = std::ratio_multiply<typename Lhs::Mass, typename Rhs::Mass>;
  using Current = std::ratio_multiply<typename Lhs::Current, typename Rhs::Current>;
  using Temperature = std::ratio_multiply<typename Lhs::Temperature, typename Rhs::Temperature>;
  using Amount = std::ratio_multiply<typename Lhs::Amount, typename Rhs::Amount>;
  using Intensity = std::ratio_multiply<typename Lhs::Intensity, typename Rhs::Intensity>;

  using result_t = unit_t<Time::num,
                          Length::num,
                          Mass::num,
                          Current::num,
                          Temperature::num,
                          Amount::num,
                          Intensity::num,
                          Time::den,
                          Length::den,
                          Mass::den,
                          Current::den,
                          Temperature::den,
                          Amount::den,
                          Intensity::den>;

};

template<typename Lhs, typename Rhs>
struct unit_product_calc_t
{
  using Time = std::ratio_add<typename Lhs::Time, typename Rhs::Time>;
  using Length = std::ratio_add<typename Lhs::Length, typename Rhs::Length>;
  using Mass = std::ratio_add<typename Lhs::Mass, typename Rhs::Mass>;
  using Current = std::ratio_add<typename Lhs::Current, typename Rhs::Current>;
  using Temperature = std::ratio_add<typename Lhs::Temperature, typename Rhs::Temperature>;
  using Amount = std::ratio_add<typename Lhs::Amount, typename Rhs::Amount>;
  using Intensity = std::ratio_add<typename Lhs::Intensity, typename Rhs::Intensity>;

  using result_t = unit_t<Time::num,
                          Length::num,
                          Mass::num,
                          Current::num,
                          Temperature::num,
                          Amount::num,
                          Intensity::num,
                          Time::den,
                          Length::den,
                          Mass::den,
                          Current::den,
                          Temperature::den,
                          Amount::den,
                          Intensity::den>;
};

template<typename Lhs, typename Rhs>
struct unit_quotient_calc_t
{
  using Time = std::ratio_subtract<typename Lhs::Time, typename Rhs::Time>;
  using Length = std::ratio_subtract<typename Lhs::Length, typename Rhs::Length>;
  using Mass = std::ratio_subtract<typename Lhs::Mass, typename Rhs::Mass>;
  using Current = std::ratio_subtract<typename Lhs::Current, typename Rhs::Current>;
  using Temperature = std::ratio_subtract<typename Lhs::Temperature, typename Rhs::Temperature>;
  using Amount = std::ratio_subtract<typename Lhs::Amount, typename Rhs::Amount>;
  using Intensity = std::ratio_subtract<typename Lhs::Intensity, typename Rhs::Intensity>;

  using result_t = unit_t<Time::num,
                          Length::num,
                          Mass::num,
                          Current::num,
                          Temperature::num,
                          Amount::num,
                          Intensity::num,
                          Time::den,
                          Length::den,
                          Mass::den,
                          Current::den,
                          Temperature::den,
                          Amount::den,
                          Intensity::den>;

};

} // namespace detail

template<typename Lhs, typename Rhs>
using unit_pow_t = typename detail::unit_pow_calc_t<Lhs, Rhs>::result_t;

template<typename Lhs, typename Rhs>
using unit_product_t = typename detail::unit_product_calc_t<Lhs, Rhs>::result_t;

template<typename Lhs, typename Rhs>
using unit_quotient_t = typename detail::unit_quotient_calc_t<Lhs, Rhs>::result_t;

}
