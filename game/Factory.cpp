#include <odp/EntityObserver.h>
#include "Factory.h"
Boss* Factory::createBoss(BossType type, const Vector2D& position) {
    return nullptr;
}

Boss* Factory::createBoss(Biome biome, const Vector2D& position) {
    return nullptr;
}

Minion* Factory::createMinion(MinionType type, const Vector2D& position) {
    return nullptr;
}

Minion* Factory::createMinion(Biome biome, const Vector2D& position) {
    return nullptr;
}

NPC* Factory::createNPC(NPCType type, const Vector2D& position) {
    return nullptr;
}

Pet* Factory::createPet(PetType type, const Vector2D& position) {
    return nullptr;
}

Player* Factory::createPlayer(PlayerType type, const Vector2D& position) {
    Scheduler& scheduler = Scheduler::getInstance();
    Player* player;
    switch (type) {
        case DOM_PROGRAMMER:
            break;
        case PLAYER_SIZE:
            break;
    }
    return player;
}

Barrier* Factory::createBarrier(std::vector<Border> borders, const Vector2D& position) {
    return nullptr;
}

Chasm* Factory::createChasm(std::vector<Border> borders, const Vector2D& position) {
    return nullptr;
}

Door* Factory::createDoor(DoorType type, Biome biome, const Vector2D& position) {
    return nullptr;
}

Tile* Factory::createTile(unsigned int index, unsigned int frame, Biome biome, const Vector2D& position) {
    return nullptr;
}

ActiveItem* Factory::createActiveItem(ActiveItemType type) {
    return nullptr;
}

ActiveItem* Factory::createActiveItem(Biome biome) {
    return nullptr;
}

PassiveItem* Factory::createPassiveItem(PassiveItemType type) {
    return nullptr;
}

PassiveItem* Factory::createPassiveItem(Biome biome) {
    return nullptr;
}

QuestItem* Factory::createQuestItem(QuestItemType type) {
    return nullptr;
}

MeleeWeapon* Factory::createMeleeWeapon(MeleeWeaponType Type) {
    return nullptr;
}

MeleeWeapon* Factory::createMeleeWeapon(Biome biome) {
    return nullptr;
}

RangedWeapon* Factory::createRangedWeapon(RangedWeaponType type) {
    return nullptr;
}

RangedWeapon* Factory::createRangedWeapon(Biome biome) {
    return nullptr;
}
