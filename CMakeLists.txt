cmake_minimum_required(VERSION 3.3)
project(concurrent_pso)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Main.cpp)
add_executable(concurrent_pso ${SOURCE_FILES})
