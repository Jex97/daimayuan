cmake_minimum_required(VERSION 3.21)
project(daimayuan)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE DP_SRC DP/*.cpp)
add_executable(daimayuan main.cpp ${DP_SRC} DP/401.cpp DP/402.cpp  DP/403.cpp DP/404.cpp DP/405.cpp DP/501.cpp DP/502.cpp DP/503.cpp DP/601.cpp DP/602.cpp DP/603.cpp DP/604.cpp test.cpp DP/701.cpp DP/702.cpp DP/703.cpp DP/704.cpp DP/705.cpp bishi/huawei20220831/3.cpp bishi/huawei20220831/2.cpp DP/801.cpp bishi/shenxinfu/2.cpp DP/802.cpp DP/803.cpp DP/804.cpp bishi/jingdong/3.cpp)
