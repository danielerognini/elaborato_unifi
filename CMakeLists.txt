cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Game main.cpp GameEngine/Engine.cpp GameEngine/Engine.h GameEngine/Entity.cpp GameEngine/Engine.h GameEngine/Input.cpp GameEngine/Input.h GameEngine/Manager.cpp GameEngine/Manager.h GameEngine/Map.cpp GameEngine/Map.h GameEngine/Room.cpp GameEngine/Room.h GameEngine/Texture.cpp GameEngine/Texture.h GameEngine/Vector2D.cpp GameEngine/Vector2D.h GameEngine/Components/Transform.cpp GameEngine/Components/Transform.h GameEngine/Components/Collider.cpp GameEngine/Components/Collider.h GameEngine/Components/Sprite.cpp GameEngine/Components/Sprite.h GameEngine/Components/Light.cpp GameEngine/Components/Light.h GameEngine/Animation.cpp GameEngine/Animation.h)
target_link_libraries(Game SDL2 SDL2_image SDL2_ttf SDL2_mixer)