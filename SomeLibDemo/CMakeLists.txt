cmake_minimum_required(VERSION 4.0.2)
project(Adder)
add_library(Adder adder.cpp)
target_include_directories(Adder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})