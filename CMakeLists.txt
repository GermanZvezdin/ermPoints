cmake_minimum_required(VERSION 3.17)
project(ermits_function)

set(CMAKE_CXX_STANDARD 11)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

add_executable(ermits_function main.cpp polinoms.cpp polinoms.hpp)
SET(GCC_COVERAGE_LINK_FLAGS "larmadillo")
#SET(CMAKE_EXE_LINKER_FLAGS  "/usr/local/include")

target_link_libraries(ermits_function main.cpp polinoms.cpp polinoms.hpp ${ARMADILLO_LIBRARIES})