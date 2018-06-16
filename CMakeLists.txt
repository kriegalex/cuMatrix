# require cmake 3.9 for CUDA support
cmake_minimum_required(VERSION 3.9)

# we use c++ and cuda
project(cuMatrix CXX CUDA)
# we want C++14 at least by default
set(CMAKE_CXX_STANDARD 14)

# compile warnings
set(WARNING_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${WARNING_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS}")

# add subdirs
add_subdirectory(core)
add_subdirectory(cuda)