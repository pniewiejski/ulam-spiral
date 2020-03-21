cmake_minimum_required(VERSION 3.0.0)
project(ulam-spiral)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)
 
option(USE_DEBUG "Enter debug mode" OFF)

include_directories(
  ${PROJECT_SOURCE_DIR}/include/
)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)