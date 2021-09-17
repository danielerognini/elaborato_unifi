cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(ENGINE_SOURCE_FILES
        Engine.cpp Engine.h
        ecs/Entity.cpp Engine.h
        odp/Input.cpp odp/Input.h
        ecs/Manager.cpp ecs/Manager.h
        Vector2D.cpp Vector2D.h
        ecs/components/Transform.cpp ecs/components/Transform.h
        ecs/components/Collider.cpp ecs/components/Collider.h
        ecs/components/Sprite.cpp ecs/components/Sprite.h
        ecs/components/Animation.cpp ecs/components/Animation.h
        Activatable.cpp Activatable.h
        collisions/Collision.cpp collisions/Collision.h
        Utility.h
        ecs/components/Text.cpp ecs/components/Text.h
        odp/EntityObserver.cpp odp/EntityObserver.h
        odp/Observer.cpp odp/Observer.h
        collisions/Border.cpp collisions/Border.h)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_library(engine STATIC ${ENGINE_SOURCE_FILES})
target_link_libraries(engine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY})

