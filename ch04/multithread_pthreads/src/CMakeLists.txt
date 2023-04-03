cmake_minimum_required(VERSION 3.13)
project(multithread_pthreads)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(multithread_pthreads ${SOURCE_FILES})