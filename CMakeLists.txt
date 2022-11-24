cmake_minimum_required(VERSION 3.22)
project(tannenbaum C)

set(CMAKE_C_STANDARD 90)
add_compile_options(-Wall -ansi -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition)

add_executable(tannenbaum main.c main.h)
