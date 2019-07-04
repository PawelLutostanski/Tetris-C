cmake_minimum_required(VERSION 3.13)
project(Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(Project)

add_executable(Project
        main.c
        structure.h
        tablefunctions.h
        tablefunctions.c)
