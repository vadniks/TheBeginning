cmake_minimum_required(VERSION 3.19)
project(tvpo7 C)

set(CMAKE_C_STANDARD 11)

add_executable(tvpo7 main.c stateMachine.h stateMachine.c)
