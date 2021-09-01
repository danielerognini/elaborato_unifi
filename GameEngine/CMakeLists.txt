cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(ENGINE_SOURCE_FILES
        Engine.cpp Engine.h
        ECS/Entity.cpp Engine.h
        ODP/Input.cpp ODP/Input.h
        ECS/Manager.cpp ECS/Manager.h
        Vector2D.cpp Vector2D.h
        ECS/Components/Transform.cpp ECS/Components/Transform.h
        ECS/Components/Collider.cpp ECS/Components/Collider.h
        ECS/Components/Sprite.cpp ECS/Components/Sprite.h
        ECS/Components/Animation.cpp ECS/Components/Animation.h
        Activatable.cpp Activatable.h
        Collisions/Collision.cpp Collisions/Collision.h
        Utility.h
        ECS/Components/Text.cpp ECS/Components/Text.h
        ODP/ControlObserver.cpp ODP/ControlObserver.h
        ODP/Observer.cpp ODP/Observer.h
        Collisions/Border.cpp Collisions/Border.h ODP/SystemObserver.cpp ODP/SystemObserver.h)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_library(GameEngine STATIC ${ENGINE_SOURCE_FILES})
target_link_libraries(GameEngine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2TTF_LIBRARY})

