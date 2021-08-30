cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./lib/googletest)
set(GTEST_SOURCE_DIR lib/googletest)
include_directories(../GameEngine ../GameSrc ${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp unit_testing/SpriteTest.cpp unit_testing/ColliderTest.cpp unit_testing/EngineTest.cpp unit_testing/ManagerTest.cpp unit_testing/Vector2DTest.cpp unit_testing/EntityTest.cpp unit_testing/CollisionTest.cpp)

add_executable(Test ${TEST_SOURCE_FILES})

target_link_libraries(Test gtest gtest_main GameEngine GameSrc)