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

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "minisi/unit.h"

using namespace minisi;

BOOST_AUTO_TEST_CASE(unit_pow_test)
{
  using unit1_t = unit_t<1, 1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8>;
  using unit2_t = unit_t<2, 3, 4, 5, 6, 7, 8, 1, 1, 1, 1, 1, 1, 1>;

  using pow_t = unit_pow_t<unit1_t, unit2_t>;

  BOOST_CHECK_EQUAL(pow_t::Time::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Time::den, 1);
  BOOST_CHECK_EQUAL(pow_t::Length::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Length::den, 1);
  BOOST_CHECK_EQUAL(pow_t::Mass::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Mass::den, 1);
  BOOST_CHECK_EQUAL(pow_t::Current::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Current::den, 1);
  BOOST_CHECK_EQUAL(pow_t::Temperature::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Temperature::den, 1);
  BOOST_CHECK_EQUAL(pow_t::Amount::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Amount::den, 1);
  BOOST_CHECK_EQUAL(pow_t::Intensity::num, 1);
  BOOST_CHECK_EQUAL(pow_t::Intensity::den, 1);
}

BOOST_AUTO_TEST_CASE(unit_product_test)
{
  using unit1_t = unit_t<1, 1, 1, 1, 1, 1, 1, 3, 4, 5, 6, 7, 8, 9>;
  using unit2_t = unit_t<2, 3, 4, 5, 6, 7, 8, 3, 4, 5, 6, 7, 8, 9>;

  using product_t = unit_product_t<unit1_t, unit2_t>;

  BOOST_CHECK_EQUAL(product_t::Time::num, 1);
  BOOST_CHECK_EQUAL(product_t::Time::den, 1);
  BOOST_CHECK_EQUAL(product_t::Length::num, 1);
  BOOST_CHECK_EQUAL(product_t::Length::den, 1);
  BOOST_CHECK_EQUAL(product_t::Mass::num, 1);
  BOOST_CHECK_EQUAL(product_t::Mass::den, 1);
  BOOST_CHECK_EQUAL(product_t::Current::num, 1);
  BOOST_CHECK_EQUAL(product_t::Current::den, 1);
  BOOST_CHECK_EQUAL(product_t::Temperature::num, 1);
  BOOST_CHECK_EQUAL(product_t::Temperature::den, 1);
  BOOST_CHECK_EQUAL(product_t::Amount::num, 1);
  BOOST_CHECK_EQUAL(product_t::Amount::den, 1);
  BOOST_CHECK_EQUAL(product_t::Intensity::num, 1);
  BOOST_CHECK_EQUAL(product_t::Intensity::den, 1);
}

BOOST_AUTO_TEST_CASE(unit_quotient_test)
{
  using unit1_t = unit_t<1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1>;

  using unit2_t = unit_t<2, 3, 4, 5, 6, 7, 8, 3, 4, 5, 6, 7, 8, 9>;

  using quotient_t = unit_quotient_t<unit1_t, unit2_t>;

  BOOST_CHECK_EQUAL(quotient_t::Time::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Time::den, 3);
  BOOST_CHECK_EQUAL(quotient_t::Length::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Length::den, 4);
  BOOST_CHECK_EQUAL(quotient_t::Mass::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Mass::den, 5);
  BOOST_CHECK_EQUAL(quotient_t::Current::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Current::den, 6);
  BOOST_CHECK_EQUAL(quotient_t::Temperature::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Temperature::den, 7);
  BOOST_CHECK_EQUAL(quotient_t::Amount::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Amount::den, 8);
  BOOST_CHECK_EQUAL(quotient_t::Intensity::num, 1);
  BOOST_CHECK_EQUAL(quotient_t::Intensity::den, 9);
}
