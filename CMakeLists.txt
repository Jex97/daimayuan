cmake_minimum_required(VERSION 3.21)
project(daimayuan)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE DP_SRC DP/*.cpp)
add_executable(daimayuan main.cpp ${DP_SRC})
