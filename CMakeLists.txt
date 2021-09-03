cmake_minimum_required(VERSION 3.19)
project(Game)

set(CMAKE_CXX_STANDARD 14)

set(GAME_SOURCE_FILES
        GameSrc/Map.cpp GameSrc/Map.h
        GameSrc/Room.cpp GameSrc/Room.h
        GameSrc/Game.cpp
        GameSrc/Cursor.cpp GameSrc/Cursor.h
        GameSrc/Bullet.cpp GameSrc/Bullet.h
        GameSrc/Creatures/NPC.cpp GameSrc/Creatures/NPC.h
        GameSrc/Creatures/Player.cpp GameSrc/Creatures/Player.h
        GameSrc/UI/Widget.cpp GameSrc/UI/Widget.h
        GameSrc/UI/Button.cpp GameSrc/UI/Button.h
        GameSrc/UI/Window.cpp GameSrc/UI/Window.h
        GameSrc/Creatures/Enemy.cpp GameSrc/Creatures/Enemy.h
        GameSrc/Creatures/Minion.cpp GameSrc/Creatures/Minion.h
        GameSrc/Creatures/Boss.cpp GameSrc/Creatures/Boss.h
        GameSrc/Creatures/Pet.cpp GameSrc/Creatures/Pet.h
        GameSrc/Scheduler.cpp GameSrc/Scheduler.h
        GameSrc/Interactable.cpp GameSrc/Interactable.h
        GameSrc/Enviroment/Tile.cpp GameSrc/Enviroment/Tile.h
        GameSrc/Enviroment/Wall.cpp GameSrc/Enviroment/Wall.h
        GameSrc/Items/Item.cpp GameSrc/Items/Item.h
        GameSrc/Items/PassiveItem.cpp GameSrc/Items/PassiveItem.h
        GameSrc/Items/ActiveItem.cpp GameSrc/Items/ActiveItem.h
        GameSrc/Items/QuestItem.cpp GameSrc/Items/QuestItem.h
        GameSrc/Items/Weapon.cpp GameSrc/Items/Weapon.h
        GameSrc/Items/RangedWeapon.cpp GameSrc/Items/RangedWeapon.h
        GameSrc/Items/MeleeWeapon.cpp GameSrc/Items/MeleeWeapon.h
        GameSrc/Inventory.cpp GameSrc/Inventory.h)

include_directories(./GameEngine)

add_executable(Game ${GAME_SOURCE_FILES})
target_link_libraries(Game GameEngine)