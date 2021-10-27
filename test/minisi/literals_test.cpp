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

#include "minisi/literals.h"
#include "minisi/io.h"

using namespace minisi;

BOOST_AUTO_TEST_CASE(literals_test)
{
  using namespace minisi::literals;
  BOOST_CHECK_EQUAL( 10.0_m, 10.0 * metre );
  BOOST_CHECK_EQUAL( 10.0_m², 10.0 * metre * metre );
  BOOST_CHECK_EQUAL( 10.0_s, 10.0 * second );
  BOOST_CHECK_EQUAL( 100.0_kg, 100.0 * kilogram );
  BOOST_CHECK_EQUAL( 1.0_N, 1.0 * newton );
  BOOST_CHECK_EQUAL( 543.0_J, 543.0 * joule );
  BOOST_CHECK_EQUAL( 100.0_W, 100.0 * watt );
  BOOST_CHECK_EQUAL( 3.6_mps, 3.6 * metre / second );
  BOOST_CHECK_EQUAL( 9.81_mps², 9.81 * metre / (second * second) );
  BOOST_CHECK_EQUAL( 6.53_mps³, 6.53 * metre / second / second / second );
  BOOST_CHECK_EQUAL( 70.0_kmph, 70.0 * kilometre / hour );
  BOOST_CHECK_EQUAL( 1.0_t, 1.0 * ton);
}
