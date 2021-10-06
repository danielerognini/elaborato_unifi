cmake_minimum_required(VERSION 3.19)
project(game)

set(CMAKE_CXX_STANDARD 20)

set(GAME_SOURCE_FILES
        game/Map.cpp game/Map.h
        game/Room.cpp game/Room.h
        game/Game.cpp
        game/Cursor.cpp game/Cursor.h
        game/Bullet.cpp game/Bullet.h
        game/creatures/npcs/NPC.cpp game/creatures/npcs/NPC.h
        game/creatures/players/Player.cpp game/creatures/players/Player.h
        game/ui/Widget.cpp game/ui/Widget.h
        game/creatures/enemies/Enemy.cpp game/creatures/enemies/Enemy.h
        game/creatures/enemies/minions/Minion.cpp game/creatures/enemies/minions/Minion.h
        game/creatures/enemies/bosses/Boss.cpp game/creatures/enemies/bosses/Boss.h
        game/creatures/pets/Pet.cpp game/creatures/pets/Pet.h
        game/Scheduler.cpp game/Scheduler.h
        game/Interactable.cpp game/Interactable.h
        game/enviroment/Tile.cpp game/enviroment/Tile.h
        game/enviroment/Barrier.cpp game/enviroment/Barrier.h
        game/items/Item.cpp game/items/Item.h
        game/items/passive-item/PassiveItem.cpp game/items/passive-item/PassiveItem.h
        game/items/active-item/ActiveItem.cpp game/items/active-item/ActiveItem.h
        game/items/quest-item/QuestItem.cpp game/items/quest-item/QuestItem.h
        game/items/weapons/Weapon.cpp game/items/weapons/Weapon.h
        game/items/weapons/ranged/RangedWeapon.cpp game/items/weapons/ranged/RangedWeapon.h
        game/items/weapons/melee/MeleeWeapon.cpp game/items/weapons/melee/MeleeWeapon.h
        game/Inventory.cpp game/Inventory.h
        game/enviroment/Door.cpp game/enviroment/Door.h
        game/enviroment/Chasm.cpp game/enviroment/Chasm.h
        game/enviroment/CollisionArea.cpp game/enviroment/CollisionArea.h
        game/ui/Menu.cpp game/ui/Menu.h
        game/Utils.h game/Factory.cpp game/Factory.h game/creatures/enemies/minions/Slime.cpp game/creatures/enemies/minions/Slime.h game/creatures/pets/Gatu.cpp game/creatures/pets/Gatu.h game/creatures/pets/Gerry.cpp game/creatures/pets/Gerry.h)

include_directories(engine test)
add_subdirectory(./test)
add_subdirectory(./engine)

add_executable(game ${GAME_SOURCE_FILES})
target_link_libraries(game engine)