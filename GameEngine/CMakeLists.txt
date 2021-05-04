cmake_minimum_required(VERSION 3.19)
project(GameEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(ENGINE_SOURCE_FILES
        Engine.cpp Engine.h
        ECS/Entity.cpp Engine.h
        Input.cpp Input.h
        ECS/Manager.cpp ECS/Manager.h
        Texture.cpp Texture.h
        Vector2D.cpp Vector2D.h
        ECS/Components/Transform.cpp ECS/Components/Transform.h
        ECS/Components/Collider.cpp ECS/Components/Collider.h
        ECS/Components/Sprite.cpp ECS/Components/Sprite.h
        ECS/Components/Light.cpp ECS/Components/Light.h
        ECS/Components/Animation.cpp ECS/Components/Animation.h
        Activatable.cpp Activatable.h Collision.cpp Collision.h Utility.h)

add_executable(GameEngine ${ENGINE_SOURCE_FILES})