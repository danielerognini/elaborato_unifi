cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(GameEngine GameSrc test)
add_subdirectory(./GameEngine)
add_subdirectory(./GameSrc)
add_subdirectory(./test)

add_executable(Game main.cpp)
target_link_libraries(Game GameEngine GameSrc)