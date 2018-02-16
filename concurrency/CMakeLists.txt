cmake_minimum_required(VERSION 3.10.1)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -lpthread")

project(learn)
add_executable(
learn
main.cpp
generateQueue.cpp
generateQueue.h
)