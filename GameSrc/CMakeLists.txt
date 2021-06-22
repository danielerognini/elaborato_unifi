cmake_minimum_required(VERSION 3.19)
project(GameSrc)

set(CMAKE_CXX_STANDARD 14)

set(GAME_SOURCE_FILES
        Map.cpp Map.h
        Room.cpp Room.h)

add_library(GameSrc ${GAME_SOURCE_FILES})