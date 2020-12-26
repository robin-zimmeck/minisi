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

#include "minisi/minisi.h"
#include "minisi/io.h"

using namespace minisi;

BOOST_AUTO_TEST_CASE(value_access_test)
{
  dimensionless_t dimless{42.0};

  length_t l{23.0};
  length_t length = length_t::from_value(10.0);
  BOOST_CHECK_EQUAL(length.value(), 10.0);
  BOOST_CHECK_EQUAL(length, 10.0 * metre);

  BOOST_CHECK(metre / metre == 1.0);
}

BOOST_AUTO_TEST_CASE(unary_arithmetic_operators_test)
{
  BOOST_CHECK_EQUAL(1.0 * metre, +(1.0 * metre));
  BOOST_CHECK_EQUAL(-1.0 * metre, -(1.0 * metre));
}

BOOST_AUTO_TEST_CASE(binary_arithmetic_operators_test)
{
  BOOST_CHECK_EQUAL(10.0 * metre + 20.0 * metre, 30.0 * metre);
  BOOST_CHECK_EQUAL(30.0 * metre - 10.0 * metre, 20.0 * metre);

  BOOST_CHECK_EQUAL(10.0 * metre / ( 5.0 * second ), 2.0 * metre / second);
  BOOST_CHECK_EQUAL(1000.0 * watt * 1.0 * hour, 3600000.0 * joule);
}

BOOST_AUTO_TEST_CASE(arithmetic_assignment_operators_test)
{
  auto timer = 10.0 * second;

  timer += 2.0 * second;
  BOOST_CHECK_EQUAL(timer, 12.0 * second);

  timer -= 4.0 * second;
  BOOST_CHECK_EQUAL(timer, 8.0 * second);

  timer *= 2.0;
  BOOST_CHECK_EQUAL(timer, 16.0 * second);

  timer /= 4.0;
  BOOST_CHECK_EQUAL(timer, 4.0 * second);

  timer *= (5.0 * dimensionless);
  BOOST_CHECK_EQUAL(timer, 20.0 * second);

  timer /= (10.0 * dimensionless);
  BOOST_CHECK_EQUAL(timer, 2.0 * second);
}

BOOST_AUTO_TEST_CASE(free_operators_test)
{
  BOOST_CHECK_EQUAL(10.0 * metre, metre * 10.0);
  BOOST_CHECK_EQUAL(440.0 / second, 880.0 / second / 2.0);
}

BOOST_AUTO_TEST_CASE(comparison_operators_test)
{
  BOOST_CHECK_EQUAL(true, 8.0 * metre < 9000.0 * metre);
  BOOST_CHECK_EQUAL(false, 9000.0 * metre < 9000.0 * metre);
  BOOST_CHECK_EQUAL(false, 32767.0 * metre < 9000.0 * metre);

  BOOST_CHECK_EQUAL(true, 8.0 * metre <= 9000.0 * metre);
  BOOST_CHECK_EQUAL(true, 9000.0 * metre <= 9000.0 * metre);
  BOOST_CHECK_EQUAL(false, 32767.0 * metre <= 9000.0 * metre);

  BOOST_CHECK_EQUAL(false, 8.0 * metre == 9000.0 * metre);
  BOOST_CHECK_EQUAL(true, 9000.0 * metre == 9000.0 * metre);
  BOOST_CHECK_EQUAL(false, 32767.0 * metre == 9000.0 * metre);

  BOOST_CHECK_EQUAL(true, 8.0 * metre != 9000.0 * metre);
  BOOST_CHECK_EQUAL(false, 9000.0 * metre != 9000.0 * metre);
  BOOST_CHECK_EQUAL(true, 32767.0 * metre != 9000.0 * metre);

  BOOST_CHECK_EQUAL(false, 8.0 * metre >= 9000.0 * metre);
  BOOST_CHECK_EQUAL(true, 9000.0 * metre >= 9000.0 * metre);
  BOOST_CHECK_EQUAL(true, 32767.0 * metre >= 9000.0 * metre);

  BOOST_CHECK_EQUAL(false, 8.0 * metre > 9000.0 * metre);
  BOOST_CHECK_EQUAL(false, 9000.0 * metre > 9000.0 * metre);
  BOOST_CHECK_EQUAL(true, 32767.0 * metre > 9000.0 * metre);
}
