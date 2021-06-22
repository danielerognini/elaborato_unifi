cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(./lib/googletest)
set(GTEST_SOURCE_DIR lib/googletest)
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR} ../GameEngine ../GameSrc)

set(TEST_SOURCE_FILES runAllTests.cpp unit_testing/SpriteTest.cpp)

add_executable(Test ${TEST_SOURCE_FILES})

target_link_libraries(Test gtest gtest_main GameSrc GameEngine)