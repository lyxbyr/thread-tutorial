cmake_minimum_required(VERSION 3.4)
project(thread_learn)

#set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -pthread" )


add_executable(thread_learn main.cpp)