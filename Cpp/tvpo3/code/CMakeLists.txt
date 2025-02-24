cmake_minimum_required(VERSION 3.19)
project(tvpo3)

set(CMAKE_CXX_STANDARD 11)

file(GLOB sources CONFIGURE_DEPENDS "include/*.hpp" "src/*.cpp")
add_executable(tvpo3 ${sources})

include_directories(libs/test/include)
file(GLOB gtest_binaries CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/libs/test/bin/*.a")
target_link_libraries(${PROJECT_NAME} ${gtest_binaries})

include_directories(libs/cryptopp/include)
file(GLOB cryptopp_binaries CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/libs/cryptopp/bin/*.a")
target_link_libraries(${PROJECT_NAME} ${cryptopp_binaries})
