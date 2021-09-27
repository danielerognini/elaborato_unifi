cmake_minimum_required(VERSION 3.19)
project(game)

set(CMAKE_CXX_STANDARD 20)

set(GAME_SOURCE_FILES
        game/Map.cpp game/Map.h
        game/Room.cpp game/Room.h
        game/Game.cpp
        game/Cursor.cpp game/Cursor.h
        game/Bullet.cpp game/Bullet.h
        game/creatures/NPC.cpp game/creatures/NPC.h
        game/creatures/Player.cpp game/creatures/Player.h
        game/ui/Widget.cpp game/ui/Widget.h
        game/creatures/Enemy.cpp game/creatures/Enemy.h
        game/creatures/Minion.cpp game/creatures/Minion.h
        game/creatures/Boss.cpp game/creatures/Boss.h
        game/creatures/Pet.cpp game/creatures/Pet.h
        game/Scheduler.cpp game/Scheduler.h
        game/Interactable.cpp game/Interactable.h
        game/enviroment/Tile.cpp game/enviroment/Tile.h
        game/enviroment/Barrier.cpp game/enviroment/Barrier.h
        game/items/Item.cpp game/items/Item.h
        game/items/PassiveItem.cpp game/items/PassiveItem.h
        game/items/ActiveItem.cpp game/items/ActiveItem.h
        game/items/QuestItem.cpp game/items/QuestItem.h
        game/items/Weapon.cpp game/items/Weapon.h
        game/items/RangedWeapon.cpp game/items/RangedWeapon.h
        game/items/MeleeWeapon.cpp game/items/MeleeWeapon.h
        game/Inventory.cpp game/Inventory.h
        game/enviroment/Door.cpp game/enviroment/Door.h
        game/enviroment/Chasm.cpp game/enviroment/Chasm.h
        game/enviroment/CollisionArea.cpp game/enviroment/CollisionArea.h
        game/ui/Menu.cpp game/ui/Menu.h
        game/Utils.h game/Factory.cpp game/Factory.h)

include_directories(engine test)
add_subdirectory(./test)
add_subdirectory(./engine)

add_executable(game ${GAME_SOURCE_FILES})
target_link_libraries(game engine)