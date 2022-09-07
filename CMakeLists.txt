cmake_minimum_required(VERSION 3.21)
project(daimayuan)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SRC DP/*.cpp bishi/*.cpp)
add_executable(daimayuan main.cpp ${SRC})
