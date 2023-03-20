cmake_minimum_required(VERSION 3.13)
project(unix_fork C)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(unix_fork ${SOURCE_FILES})
