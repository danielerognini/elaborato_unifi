cmake_minimum_required(VERSION 3.19)
project(GameSrc)

set(CMAKE_CXX_STANDARD 14)

set(GAME_SOURCE_FILES
        Map.cpp Map.h
        Room.cpp Room.h Game.cpp Cursor.cpp Cursor.h Bullet.cpp Bullet.h Creatures/NPC.cpp Creatures/NPC.h Creatures/Player.cpp Creatures/Player.h UI/Widget.cpp UI/Widget.h UI/Button.cpp UI/Button.h UI/Window.cpp UI/Window.h Creatures/Enemy.cpp Creatures/Enemy.h Creatures/Minion.cpp Creatures/Minion.h Creatures/Boss.cpp Creatures/Boss.h Creatures/Pet.cpp Creatures/Pet.h Scheduler.cpp Scheduler.h Interactable.cpp Interactable.h Enviroment/Tile.cpp Enviroment/Tile.h Enviroment/Wall.cpp Enviroment/Wall.h Items/Item.cpp Items/Item.h Items/PassiveItem.cpp Items/PassiveItem.h Items/ActiveItem.cpp Items/ActiveItem.h Items/QuestItem.cpp Items/QuestItem.h Items/Weapon.cpp Items/Weapon.h Items/RangedWeapon.cpp Items/RangedWeapon.h Items/MeleeWeapon.cpp Items/MeleeWeapon.h Inventory.cpp Inventory.h)

add_library(GameSrc ${GAME_SOURCE_FILES})