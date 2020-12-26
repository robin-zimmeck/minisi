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

BOOST_AUTO_TEST_CASE(derived_unit_test)
{
  BOOST_TEST(hertz == 1.0 / second);
  BOOST_TEST(newton == kilogram * metre / (second * second));
  BOOST_TEST(pascal == kilogram / (metre * second * second));
  BOOST_TEST(joule == kilogram * metre * metre / (second * second));
  BOOST_TEST(watt == kilogram * metre * metre / (second * second * second));
  BOOST_TEST(coulomb == second * ampere);
  BOOST_TEST(volt == kilogram * metre * metre / (second * second * second * ampere));
  BOOST_TEST(farad == second * second * second * second * ampere * ampere / (kilogram * metre * metre));
  BOOST_TEST(ohm == kilogram * metre * metre / (second * second * second * ampere * ampere));
  BOOST_TEST(siemens == second * second * second * ampere * ampere / (kilogram * metre * metre));
  BOOST_TEST(weber == kilogram * metre * metre / (second * second * ampere));
  BOOST_TEST(tesla == kilogram / (second * second * ampere));
  BOOST_TEST(henry == kilogram * metre * metre / (second * second * ampere * ampere));
  BOOST_TEST(lumen == candela);
  BOOST_TEST(lux == lumen / (metre * metre));
  BOOST_TEST(becquerel == 1.0 / second);
  BOOST_TEST(gray == metre * metre / (second * second));
  BOOST_TEST(sievert == metre * metre / (second * second));
  BOOST_TEST(katal == mole / second);
}
