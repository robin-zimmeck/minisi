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

#include "minisi/math.h"
#include "minisi/io.h"

using namespace minisi;

BOOST_AUTO_TEST_CASE(basic_operations_test)
{
  BOOST_CHECK_EQUAL(abs(5.0 * metre), 5.0 * metre);
  BOOST_CHECK_EQUAL(abs(-5.0 * metre), 5.0 * metre);

  BOOST_CHECK_EQUAL(fmod(8.5 * second, 1.0 * second), 0.5);

  BOOST_CHECK_EQUAL(remainder(8.5 * second, 1.0 * second), 0.5);

  BOOST_CHECK_EQUAL(fma(1.0 * metre, 2.0 / second, 3.0 * metre / second), 5.0 * metre / second);
}

BOOST_AUTO_TEST_CASE(power_functions_test)
{
  BOOST_CHECK_EQUAL(pow<2>(2.0 * metre), 4.0 * metre * metre);
  BOOST_CHECK_EQUAL((pow<1, 2>(4.0 * metre * metre)), (2.0 * metre));
  BOOST_CHECK_EQUAL(sqrt(4.0 * metre * metre), 2.0 * metre);
  BOOST_CHECK_EQUAL(cbrt(8.0 * metre * metre * metre), 2.0 * metre);
  BOOST_CHECK_EQUAL(hypot(3.0 * metre, 4.0 * metre), 5.0 * metre);
  BOOST_CHECK_EQUAL(hypot(3.0 * metre, 4.0 * metre, 12.0 * metre), 13.0 * metre);
}

BOOST_AUTO_TEST_CASE(rouding_functions_test)
{
  BOOST_CHECK_EQUAL(ceil(3.2 * metre), 4.0 * metre);
  BOOST_CHECK_EQUAL(floor(3.8 * metre), 3.0 * metre);
  BOOST_CHECK_EQUAL(trunc(3.8 * metre), 3.0 * metre);
  BOOST_CHECK_EQUAL(round(3.5 * metre), 4.0 * metre);
  BOOST_CHECK_EQUAL(nearbyint(3.9 * metre), 4.0 * metre);
  BOOST_CHECK_EQUAL(rint(3.9 * metre), 4.0 * metre);
  BOOST_CHECK_EQUAL(nextafter(1.0 * metre, 2.0 * metre), std::nextafter(1.0, 2.0) * metre);
  BOOST_CHECK_EQUAL(copysign(2.0 * metre, -0.1 * metre), -2.0 * metre);
}

BOOST_AUTO_TEST_CASE(classification_test)
{
  BOOST_CHECK_EQUAL(isfinite(42.0 * metre), true);
  BOOST_CHECK_EQUAL(isfinite(std::numeric_limits<double>::quiet_NaN() * metre), false);

  BOOST_CHECK_EQUAL(isinf(42.0 * metre), false);
  BOOST_CHECK_EQUAL(isinf(std::numeric_limits<double>::infinity() * metre), true);

  BOOST_CHECK_EQUAL(isnan(42.0 * metre), false);
  BOOST_CHECK_EQUAL(isnan(std::numeric_limits<double>::quiet_NaN() * metre), true);

  BOOST_CHECK_EQUAL(isnormal(1.0 * metre), true);
}
