cmake_minimum_required(VERSION 3.13)
project(ipc_message_passing)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)

add_executable(ipc_message_passing ${SOURCE_FILES})