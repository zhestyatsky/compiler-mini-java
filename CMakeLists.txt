cmake_minimum_required(VERSION 3.10)
project(compiler-mini-java)

set(CMAKE_CXX_STANDARD              17)
set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

include(cmake/BuildFlags.cmake)
include(cmake/FindFlexBison.cmake)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

add_subdirectory(src)
add_subdirectory(samples)
