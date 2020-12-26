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

#include <sstream>

#include "minisi/math.h"
#include "minisi/io.h"
#include "minisi/literals.h"

using namespace minisi;
using namespace minisi::literals;

namespace
{
  template<typename T>
  std::string
  to_string(const T& value)
  {
    std::stringstream ss;
    ss << value;
    return ss.str();
  }
}

BOOST_AUTO_TEST_CASE(io_test)
{
  BOOST_CHECK_EQUAL(to_string(1.2_m), "1.2 m");
  BOOST_CHECK_EQUAL(to_string(1.2_s), "1.2 s");
  BOOST_CHECK_EQUAL(to_string(1.2_kg), "1.2 kg");

  BOOST_CHECK_EQUAL(to_string(1.2 * second
                                  * metre * metre
                                  * kilogram * kilogram * kilogram
                                  * ampere * ampere * ampere * ampere
                                  /
                                  (  kelvin
                                   * mole * mole
                                   * candela * candela * candela)),
                      "1.2 s·m²·kg³·A⁴·K⁻¹·mol⁻²·cd⁻³");

  BOOST_CHECK_EQUAL(to_string(sqrt(4.0 * metre)), "2 m¹⸍²");
}
