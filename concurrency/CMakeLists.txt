cmake_minimum_version(VERSION 3.5.1)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

project(learn)
add_executable(
learn
main.cpp
generateQueue.cpp
generateQueue.h
)