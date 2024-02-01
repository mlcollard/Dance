# Build for Dance program

cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(Dance)

add_executable(dance)
target_sources(dance PRIVATE dance.cpp)
