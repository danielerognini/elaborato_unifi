cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(GameEngine)

set(GAME_SOURCE_FILES GameSrc/Map.cpp GameSrc/Map.h GameSrc/Room.cpp GameSrc/Room.h test/runAllTests.cpp)

add_executable(Game main.cpp)
add_library(core ${GAME_SOURCE_FILES})
target_link_libraries(GameEngine core lib)