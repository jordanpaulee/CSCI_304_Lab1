cmake_minimum_required(VERSION 3.26)
project(CSCI304Lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSCI304Lab1
        gdbtest.c
        lab1p1.txt
        README.md)
