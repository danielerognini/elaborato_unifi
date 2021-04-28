cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Tests runAllTests.cpp)

target_link_libraries(Tests gtest gtest_main core GameEngine)