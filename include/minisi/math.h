/*
  Copyright (c) 2020, Robin Zimmeck <robin@robin-zimmeck.de>
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  
  1. Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.
  
  2. Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.
  
  This software is provided by the copyright holders and contributors "as is"
  and any express or implied warranties, including, but not limited to, the
  implied warranties of merchantability and fitness for a particular purpose are
  disclaimed. In no event shall the copyright owner or contributors be liable
  for any direct, indirect, incidental, special, exemplary, or consequential
  damages (including, but not limited to, procurement of substitute goods or
  services; loss of use, data, or profits; or business interruption) however
  caused and on any theory of liability, whether in contract, strict liability,
  or tort (including negligence or otherwise) arising in any way out of the use
  of this software, even if advised of the possibility of such damage.
*/

#pragma once

#include "minisi.h"
#include "minisi/unit.h"

#include <cmath>

namespace minisi
{


// --------------------------------------------------------------------------------------------------------------------
// basic operations

template<typename Unit>
quantity_t<Unit>
abs(quantity_t<Unit> arg)
{
 return quantity_t<Unit>::from_value(std::abs(arg.value()));
}

template<typename LhsUnit, typename RhsUnit>
auto
fmod(quantity_t<LhsUnit> lhs,
     quantity_t<RhsUnit> rhs)
{
  return quantity_t<unit_quotient_t<LhsUnit, RhsUnit>>::from_value(std::fmod(lhs.value(), rhs.value()));
}

template<typename LhsUnit, typename RhsUnit>
auto
remainder(quantity_t<LhsUnit> lhs,
          quantity_t<RhsUnit> rhs)
{
  return quantity_t<unit_quotient_t<LhsUnit, RhsUnit>>::from_value(std::remainder(lhs.value(), rhs.value()));
}

template<typename LhsUnit, typename RhsUnit>
auto
fma(quantity_t<LhsUnit> x,
    quantity_t<RhsUnit> y,
    quantity_t<unit_product_t<LhsUnit, RhsUnit>> z)
{
  return quantity_t<unit_product_t<LhsUnit, RhsUnit>>::from_value(std::fma(x.value(), y.value(), z.value()));
}

// --------------------------------------------------------------------------------------------------------------------
// power functions

template<int Exp, typename Unit>
auto
pow(quantity_t<Unit> base)
{
  using powUnit_t = unit_t<Exp, Exp, Exp, Exp, Exp, Exp, Exp, 1, 1, 1, 1, 1, 1, 1>;
  return quantity_t<unit_pow_t<Unit, powUnit_t>>::from_value(std::pow(base.value(), Exp));
}

template<int ExpNum, int ExpDen, typename Unit>
auto
pow(quantity_t<Unit> base)
{
  using powUnit_t = unit_t<ExpNum, ExpNum, ExpNum, ExpNum, ExpNum, ExpNum, ExpNum,
                           ExpDen, ExpDen, ExpDen, ExpDen, ExpDen, ExpDen, ExpDen>;

  return quantity_t<unit_pow_t<Unit, powUnit_t>>::from_value(std::pow(base.value(), double(ExpNum) / ExpDen));
}

template<typename Unit>
auto
sqrt(quantity_t<Unit> arg)
{
  using sqrtUnit_t = unit_t<1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2>;
  return quantity_t<unit_pow_t<Unit, sqrtUnit_t>>::from_value(std::sqrt(arg.value()));
}

template<typename Unit>
auto
cbrt(quantity_t<Unit> arg)
{
  using cbrtUnit_t = unit_t<1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3>;
  return quantity_t<unit_pow_t<Unit, cbrtUnit_t>>::from_value(std::cbrt(arg.value()));
}

template<typename Unit>
auto
hypot(quantity_t<Unit> x, quantity_t<Unit> y)
{
  return quantity_t<Unit>::from_value(std::hypot(x.value(), y.value()));
}

template<typename Unit>
auto
hypot(quantity_t<Unit> x, quantity_t<Unit> y, quantity_t<Unit> z)
{
  return quantity_t<Unit>::from_value(std::hypot(x.value(), y.value(), z.value()));
}

template<typename Unit>
auto
ceil(quantity_t<Unit> arg)
{
  return quantity_t<Unit>::from_value(std::ceil(arg.value()));
}

template<typename Unit>
auto
floor(quantity_t<Unit> arg)
{
  return quantity_t<Unit>::from_value(std::floor(arg.value()));
}

template<typename Unit>
auto
trunc(quantity_t<Unit> arg)
{
  return quantity_t<Unit>::from_value(std::trunc(arg.value()));
}

template<typename Unit>
auto
round(quantity_t<Unit> arg)
{
  return quantity_t<Unit>::from_value(std::round(arg.value()));
}

template<typename Unit>
auto
nearbyint(quantity_t<Unit> arg)
{
  return quantity_t<Unit>::from_value(std::nearbyint(arg.value()));
}

template<typename Unit>
auto
rint(quantity_t<Unit> arg)
{
  return quantity_t<Unit>::from_value(std::rint(arg.value()));
}

template<typename Unit>
auto
nextafter(quantity_t<Unit> from, quantity_t<Unit> to)
{
  return quantity_t<Unit>::from_value(std::nextafter(from.value(), to.value()));
}

template<typename Unit>
auto
copysign(quantity_t<Unit> x, quantity_t<Unit> y)
{
  return quantity_t<Unit>::from_value(std::copysign(x.value(), y.value()));
}


template<typename Unit>
bool
isfinite(quantity_t<Unit> arg)
{
  return std::isfinite(arg.value());
}

template<typename Unit>
bool
isinf(quantity_t<Unit> arg)
{
  return std::isinf(arg.value());
}

template<typename Unit>
bool
isnan(quantity_t<Unit> arg)
{
  return std::isnan(arg.value());
}

template<typename Unit>
bool
isnormal(quantity_t<Unit> arg)
{
  return std::isnormal(arg.value());
}

} // namespace minisi
