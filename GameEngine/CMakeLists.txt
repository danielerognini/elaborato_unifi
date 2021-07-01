cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(ENGINE_SOURCE_FILES
        Engine.cpp Engine.h
        ECS/Entity.cpp Engine.h
        Input.cpp Input.h
        ECS/Manager.cpp ECS/Manager.h
        Vector2D.cpp Vector2D.h
        ECS/Components/Transform.cpp ECS/Components/Transform.h
        ECS/Components/Collider.cpp ECS/Components/Collider.h
        ECS/Components/Sprite.cpp ECS/Components/Sprite.h
        ECS/Components/Animation.cpp ECS/Components/Animation.h
        Activatable.cpp Activatable.h
        Collision.cpp Collision.h
        Utility.h
        ECS/Components/Text.cpp ECS/Components/Text.h
        ControlObserver.cpp ControlObserver.h
        Observer.cpp Observer.h Segment.cpp Segment.h)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_library(GameEngine ${ENGINE_SOURCE_FILES})
