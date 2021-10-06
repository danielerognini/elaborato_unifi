#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <Utility.h>
#include "Scheduler.h"
#include "creatures/enemies/bosses/Boss.h"
#include "creatures/enemies/minions/Minion.h"
#include "creatures/npcs/NPC.h"
#include "creatures/pets/Pet.h"
#include "creatures/players/Player.h"
#include "enviroment/Barrier.h"
#include "enviroment/Chasm.h"
#include "enviroment/Door.h"
#include "enviroment/Tile.h"
#include "items/active-item/ActiveItem.h"
#include "items/passive-item/PassiveItem.h"
#include "items/quest-item/QuestItem.h"
#include "items/weapons/melee/MeleeWeapon.h"
#include "items/weapons/ranged/RangedWeapon.h"

enum Biome {
    CASTLE, BIOME_SIZE
};

enum BossType {
    BOSS_SIZE
};

enum MinionType {
    SLIME, LITTLE_SLIME, MINION_SIZE
};

enum NPCType {
    NPC_SIZE
};

enum PetType {
    GATU, GERRY, PET_SIZE
};

enum PlayerType {
    DOM_PROGRAMMER, PLAYER_SIZE
};

enum DoorType {
    NORTH, SOUTH, EAST, WEST, DOOR_SIZE
};

enum ActiveItemType {
    ACTIVE_ITEM_SIZE
};

enum PassiveItemType {
    PASSIVE_ITEM_SIZE
};

enum QuestItemType {
    QUEST_ITEM_SIZE
};

enum MeleeWeaponType {
    MELEE_WEAPON_SIZE
};

enum RangedWeaponType {
    RANGED_WEAPON_SIZE
};

class Factory {
public:
    static Boss* createBoss(BossType type, const Vector2D& position);
    
    static Boss* createBoss(Biome biome, const Vector2D& position);
    
    static Minion* createMinion(MinionType type, const Vector2D& position);
    
    static Minion* createMinion(Biome biome, const Vector2D& position);
    
    static NPC* createNPC(NPCType type, const Vector2D& position);
    
    static Pet* createPet(PetType type, const Vector2D& position);
    
    static Player* createPlayer(PlayerType type, const Vector2D& position);
    
    static Barrier* createBarrier(std::vector<Border> borders, const Vector2D& position);
    
    static Chasm* createChasm(std::vector<Border> borders, const Vector2D& position);
    
    static Door* createDoor(DoorType type, Biome biome, const Vector2D& position);
    
    static Tile* createTile(unsigned int index, unsigned int frame, Biome biome, const Vector2D& position);
    
    static ActiveItem* createActiveItem(ActiveItemType type);
    
    static ActiveItem* createActiveItem(Biome biome);
    
    static PassiveItem* createPassiveItem(PassiveItemType type);
    
    static PassiveItem* createPassiveItem(Biome biome);
    
    static QuestItem* createQuestItem(QuestItemType type);
    
    static MeleeWeapon* createMeleeWeapon(MeleeWeaponType Type);
    
    static MeleeWeapon* createMeleeWeapon(Biome biome);
    
    static RangedWeapon* createRangedWeapon(RangedWeaponType type);
    
    static RangedWeapon* createRangedWeapon(Biome biome);
};

#endif //GAME_FACTORY_H
