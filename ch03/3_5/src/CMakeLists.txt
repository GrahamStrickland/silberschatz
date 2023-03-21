cmake_minimum_required(VERSION 3.13)
project(ipc_shared_memory)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(ipc_shared_memory ${SOURCE_FILES})