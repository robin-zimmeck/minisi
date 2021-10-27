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

#include "unit.h"

// detect c++20 feature check support and use this to allow operator<=> to be defaulted if possible
#ifdef __has_cpp_attribute

#if __has_cpp_attribute(__cpp_lib_three_way_comparison)
#define MINISI_HAS_SPACESHIP
#endif
#endif

#if defined(MINISI_HAS_SPACESHIP)
#include <compare>
#endif

#include <type_traits>

namespace minisi
{

using dimensionless_t = quantity_t<dimensionlessUnit_t>;

template<typename Unit>
class quantity_t
{
public:
  using unit_t = Unit;

  quantity_t();

  template<typename = std::enable_if<std::is_same_v<Unit, dimensionless_t>>>
  quantity_t(double);

  // value access
  static quantity_t from_value(double);
  double value() const;

  // arithmetic operators
  quantity_t operator+() const;
  quantity_t operator-() const;
  quantity_t operator+(quantity_t) const;
  quantity_t operator-(quantity_t) const;

  template<typename ArgUnit>
  quantity_t<unit_product_t<Unit, ArgUnit>>
  operator*(quantity_t<ArgUnit>) const;

  template<typename ArgUnit>
  quantity_t<unit_quotient_t<Unit, ArgUnit>>
  operator/(quantity_t<ArgUnit>) const;

  // arithmetic assignment operators
  quantity_t &operator+=(quantity_t);
  quantity_t &operator-=(quantity_t);
  quantity_t &operator*=(dimensionless_t);
  quantity_t &operator/=(dimensionless_t);
  quantity_t &operator*=(double);
  quantity_t &operator/=(double);

  // comparison operators
#if defined(MINISI_HAS_SPACESHIP)
    auto operator<=>(const quantity_t&) const = default;
#else
  bool operator== (quantity_t) const;
  bool operator!= (quantity_t) const;
  bool operator< (quantity_t) const;
  bool operator> (quantity_t) const;
  bool operator<= (quantity_t) const;
  bool operator>= (quantity_t) const;
#endif

private:
  quantity_t(double, int);

  double m_value;
};

// free operators
template<typename Unit>
quantity_t<Unit>
operator*(quantity_t<Unit>, double);

template<typename Unit>
quantity_t<Unit>
operator*(double, quantity_t<Unit>);

template<typename Unit>
quantity_t<Unit>
operator/(quantity_t<Unit>, double);

template<typename Unit>
quantity_t<unit_quotient_t<dimensionlessUnit_t, Unit>>
operator/(double, quantity_t<Unit>);

// =================================================================================================
// definition

template<typename Unit>
quantity_t<Unit>::quantity_t()
  : m_value{}
{
}

template<typename Unit>
template<typename>
quantity_t<Unit>::quantity_t(double value)
  : m_value{value}
{
}

template<typename Unit>
quantity_t<Unit>::quantity_t(double value,
                             int)
  : m_value{value}
{
}

template<typename Unit>
auto
quantity_t<Unit>::from_value(double value) -> quantity_t
{
  return {value, 0};
}

template<typename Unit>
auto
quantity_t<Unit>::value() const -> double
{
  return m_value;
}

// -------------------------------------------------------------------------------------------------
// arithmetic operators

template<typename Unit>
auto
quantity_t<Unit>::operator+() const -> quantity_t
{
  return *this;
}

template<typename Unit>
auto
quantity_t<Unit>::operator-() const -> quantity_t
{
  return {-m_value};
}

template<typename Unit>
auto
quantity_t<Unit>::operator+(quantity_t arg) const -> quantity_t
{
  return {m_value + arg.m_value};
}

template<typename Unit>
auto
quantity_t<Unit>::operator-(quantity_t arg) const -> quantity_t
{
  return {m_value - arg.m_value};
}

template<typename Unit>
template<typename ArgUnit>
quantity_t<unit_product_t<Unit, ArgUnit>>
quantity_t<Unit>::operator*(quantity_t<ArgUnit> arg) const
{
  return quantity_t<unit_product_t<Unit, ArgUnit>>::from_value(m_value * arg.value());
}

template<typename Unit>
template<typename ArgUnit>
quantity_t<unit_quotient_t<Unit, ArgUnit>>
quantity_t<Unit>::operator/(quantity_t<ArgUnit> arg) const
{
  return quantity_t<unit_quotient_t<Unit, ArgUnit>>::from_value(m_value / arg.value());
}

// -------------------------------------------------------------------------------------------------
// arithmetic assignment operators

template<typename Unit>
auto
quantity_t<Unit>::operator+=(quantity_t other) -> quantity_t &
{
  m_value += other.m_value;
  return *this;
}

template<typename Unit>
auto
quantity_t<Unit>::operator-=(quantity_t other) -> quantity_t &
{
  m_value -= other.m_value;
  return *this;
}

template<typename Unit>
auto
quantity_t<Unit>::operator*=(dimensionless_t other) -> quantity_t &
{
  m_value *= other.value();
  return *this;
}

template<typename Unit>
auto
quantity_t<Unit>::operator/=(dimensionless_t other) -> quantity_t &
{
  m_value /= other.value();
  return *this;
}

template<typename Unit>
auto
quantity_t<Unit>::operator*=(double other) -> quantity_t &
{
  m_value *= other;
  return *this;
}

template<typename Unit>
auto
quantity_t<Unit>::operator/=(double other) -> quantity_t &
{
  m_value /= other;
  return *this;
}

// -------------------------------------------------------------------------------------------------
// comparison operators
#if !defined(MINISI_HAS_SPACESHIP)
template<typename Unit>
bool
quantity_t<Unit>::operator== (quantity_t other) const
{
  return m_value == other.m_value;
}

template<typename Unit>
bool
quantity_t<Unit>::operator!= (quantity_t other) const
{
  return m_value != other.m_value;
}

template<typename Unit>
bool
quantity_t<Unit>::operator< (quantity_t other) const
{
  return m_value < other.m_value;
}

template<typename Unit>
bool
quantity_t<Unit>::operator> (quantity_t other) const
{
  return m_value > other.m_value;
}

template<typename Unit>
bool
quantity_t<Unit>::operator<= (quantity_t other) const
{
  return m_value <= other.m_value;
}

template<typename Unit>
bool
quantity_t<Unit>::operator>= (quantity_t other) const
{
  return m_value >= other.m_value;
}
#endif
// -------------------------------------------------------------------------------------------------
// free operators

template<typename Unit>
quantity_t<Unit>
operator*(quantity_t<Unit> lhs, double rhs)
{
  return quantity_t<Unit>::from_value(lhs.value() * rhs);
}

template<typename Unit>
quantity_t<Unit>
operator*(double lhs, quantity_t<Unit> rhs)
{
  return quantity_t<Unit>::from_value(lhs * rhs.value());
}

template<typename Unit>
quantity_t<Unit>
operator/(quantity_t<Unit> lhs, double rhs)
{
  return quantity_t<Unit>::from_value(lhs.value() / rhs);
}

template<typename Unit>
quantity_t<unit_quotient_t<dimensionlessUnit_t, Unit>>
operator/(double lhs, quantity_t<Unit> rhs)
{
  return quantity_t<unit_quotient_t<dimensionlessUnit_t, Unit>>::from_value(lhs / rhs.value());
}

} // namespace minisi
