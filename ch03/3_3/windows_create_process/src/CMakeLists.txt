cmake_minimum_required(VERSION 3.13)
project(windows_create_process C)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(windows_create_process ${SOURCE_FILES})
