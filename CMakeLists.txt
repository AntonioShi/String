cmake_minimum_required(VERSION 3.8)
project(String)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c DString.h Brute-Force.h)
add_executable(String ${SOURCE_FILES} DString.h Brute-Force.h)