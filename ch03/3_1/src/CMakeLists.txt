cmake_minimum_required(VERSION 3.13)
project(memory C)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES memory.c)

add_executable(${SOURCE_FILES})
