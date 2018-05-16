# require cmake 3.9 for CUDA support
cmake_minimum_required(VERSION 3.9)

# we use c++ and cuda
project(cuMatrix CXX CUDA)
# we want C++14 at least by default
set(CMAKE_CXX_STANDARD 14)