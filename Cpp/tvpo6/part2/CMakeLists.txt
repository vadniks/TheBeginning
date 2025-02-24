cmake_minimum_required(VERSION 3.19)
project(tvpo6)

set(CMAKE_CXX_STANDARD 11)

file(GLOB sources CONFIGURE_DEPENDS "include/*.hpp" "src/*.cpp")
add_executable(tvpo6 ${sources})
