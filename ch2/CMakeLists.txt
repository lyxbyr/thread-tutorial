cmake_minimum_required(VERSION 3.20)
project(ch2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -pthread" )

add_executable(ch2 main.cpp)
