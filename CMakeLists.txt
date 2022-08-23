cmake_minimum_required(VERSION 3.21)
project(daimayuan)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE DP_SRC DP/*.cpp)
add_executable(daimayuan main.cpp ${DP_SRC} DP/401.cpp DP/402.cpp  DP/403.cpp DP/404.cpp DP/405.cpp DP/501.cpp DP/502.cpp DP/503.cpp)
