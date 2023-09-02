cmake_minimum_required(VERSION 3.26)
project(PriceMaster)

set(CMAKE_CXX_STANDARD 23)

add_executable(PriceMaster src/main.cpp
        src/Commodity.cpp
        src/Commodity.h)
