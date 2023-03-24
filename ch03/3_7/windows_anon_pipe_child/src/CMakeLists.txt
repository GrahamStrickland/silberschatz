cmake_minimum_required(VERSION 3.13)
project(windows_anon_pipe_child)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(windows_anon_pipe_child ${SOURCE_FILES})