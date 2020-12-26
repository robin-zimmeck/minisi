cmake_minimum_required( VERSION 3.18 )

project(Minisi
  LANGUAGES CXX
  VERSION 1.0.0
  DESCRIPTION "Lightweight Units Library for C++17"
)

enable_testing()
set(CMAKE_SKIP_RULE_DEPENDENCY 1)

option(MINISI_DEVELOPMENT_WARNINGS
  "Enable Warnings for Library Development"
  FALSE)

if (${MINISI_DEVELOPMENT_WARNINGS})
  add_definitions(-Weverything)
  add_definitions(-Wno-c++98-compat)
  add_definitions(-Wno-global-constructors)
  add_definitions(-Wno-c99-compat )
  add_definitions(-Wno-float-equal)
  add_definitions(-fcolor-diagnostics)
  add_definitions(-Wno-c++98-compat-pedantic)
  add_definitions(-Wno-disabled-macro-expansion)
endif()

set(CMAKE_CXX_STANDARD 17)

option(MINISI_USE_LIBCXX
  "Use libc++ instead of libstdc++"
  FALSE)

if (${MINISI_USE_LIBCXX})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi")
endif()

add_library(Minisi INTERFACE)

if (BUILD_INTERFACE)
  target_sources(Minisi INTERFACE
    include/minisi/forward.h
    include/minisi/io.h
    include/minisi/limits.h
    include/minisi/literals.h
    include/minisi/math.h
    include/minisi/minisi.h
    include/minisi/quantity.h
    include/minisi/unit.h
  )
endif()

target_include_directories(Minisi 
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if (Boost_FOUND)

  macro(minisi_add_test NAME SOURCES)
    add_executable(${NAME} ${SOURCES})
    # target_include_directories(${NAME} ${Boost_INCLUDE_DIRS})
    target_compile_definitions(${NAME} PRIVATE "BOOST_TEST_DYN_LINK=1")
    target_link_libraries(${NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} Minisi)
    add_test(${NAME} ${NAME})
  endmacro()

  minisi_add_test(io_test test/minisi/io_test.cpp)
  minisi_add_test(literals_test test/minisi/literals_test.cpp)
  minisi_add_test(math_test test/minisi/math_test.cpp)
  minisi_add_test(minisi_test test/minisi/minisi_test.cpp)
  minisi_add_test(quantity_test test/minisi/quantity_test.cpp)
  minisi_add_test(unit_test test/minisi/unit_test.cpp)
endif()

install(DIRECTORY include/minisi DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

install(TARGETS Minisi DESTINATION lib/cmake/Minisi EXPORT MinisiTargets)
install(EXPORT MinisiTargets DESTINATION lib/cmake/Minisi)
install(FILES MinisiConfig.cmake MinisiConfigVersion.cmake DESTINATION lib/cmake/Minisi)

