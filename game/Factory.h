#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <Utility.h>
#include "Scheduler.h"
#include "creatures/Boss.h"
#include "creatures/Minion.h"
#include "creatures/NPC.h"
#include "creatures/Pet.h"
#include "creatures/Player.h"
#include "enviroment/Barrier.h"
#include "enviroment/Chasm.h"
#include "enviroment/Door.h"
#include "enviroment/Tile.h"
#include "items/ActiveItem.h"
#include "items/PassiveItem.h"
#include "items/QuestItem.h"
#include "items/MeleeWeapon.h"
#include "items/RangedWeapon.h"

enum Biome {
};

enum BossType {
};

enum MinionType {
};

enum NPCType {
};

enum PetType {
};

enum PlayerType {
};

enum DoorType {
};

enum ActiveItemType {
};

enum PassiveItemType {
};

enum QuestItemType {
};

enum MeleeWeaponType {
};

enum RangedWeaponType {
};

class Factory {
public:
    static u_ptr<Boss> createBoss(BossType type, const Vector2D& position);
    
    static u_ptr<Boss> createBoss(Biome biome, const Vector2D& position);
    
    static u_ptr<Minion> createMinion(MinionType type, const Vector2D& position);
    
    static u_ptr<Minion> createMinion(Biome biome, const Vector2D& position);
    
    static u_ptr<NPC> createNPC(NPCType type, const Vector2D& position);
    
    static u_ptr<Pet> createPet(PetType type, const Vector2D& position);
    
    static u_ptr<Player> createPlayer(PlayerType type, const Vector2D& position);
    
    static u_ptr<Barrier> createBarrier(std::vector<Border> borders, const Vector2D& position);
    
    static u_ptr<Chasm> createChasm(std::vector<Border> borders, const Vector2D& position);
    
    static u_ptr<Door> createDoor(DoorType type, Biome biome, const Vector2D& position);
    
    static u_ptr<Tile> createTile(unsigned int index, unsigned int frame, Biome biome, const Vector2D& position);
    
    static u_ptr<ActiveItem> createActiveItem(ActiveItemType type);
    
    static u_ptr<ActiveItem> createActiveItem(Biome biome);
    
    static u_ptr<PassiveItem> createPassiveItem(PassiveItemType type);
    
    static u_ptr<PassiveItem> createPassiveItem(Biome biome);
    
    static u_ptr<QuestItem> createQuestItem(QuestItemType type);
    
    static u_ptr<MeleeWeapon> createMeleeWeapon(MeleeWeaponType Type);
    
    static u_ptr<MeleeWeapon> createMeleeWeapon(Biome biome);
    
    static u_ptr<RangedWeapon> createRangedWeapon(RangedWeaponType type);
    
    static u_ptr<RangedWeapon> createRangedWeapon(Biome biome);
};

#endif //GAME_FACTORY_H
