#include "Factory.h"

u_ptr<Boss> Factory::createBoss(BossType type, const Vector2D& position) {
    return u_ptr<Boss>();
}

u_ptr<Boss> Factory::createBoss(Biome biome, const Vector2D& position) {
    return u_ptr<Boss>();
}

u_ptr<Minion> Factory::createMinion(MinionType type, const Vector2D& position) {
    return u_ptr<Minion>();
}

u_ptr<Minion> Factory::createMinion(Biome biome, const Vector2D& position) {
    return u_ptr<Minion>();
}

u_ptr<NPC> Factory::createNPC(NPCType type, const Vector2D& position) {
    return u_ptr<NPC>();
}

u_ptr<Pet> Factory::createPet(PetType type, const Vector2D& position) {
    return u_ptr<Pet>();
}

u_ptr<Player> Factory::createPlayer(PlayerType type, const Vector2D& position) {
    return u_ptr<Player>();
}

u_ptr<Barrier> Factory::createBarrier(std::vector<Border> borders, const Vector2D& position) {
    return u_ptr<Barrier>();
}

u_ptr<Chasm> Factory::createChasm(std::vector<Border> borders, const Vector2D& position) {
    return u_ptr<Chasm>();
}

u_ptr<Door> Factory::createDoor(DoorType type, Biome biome, const Vector2D& position) {
    return u_ptr<Door>();
}

u_ptr<Tile> Factory::createTile(unsigned int index, unsigned int frame, Biome biome, const Vector2D& position) {
    return u_ptr<Tile>();
}

u_ptr<ActiveItem> Factory::createActiveItem(ActiveItemType) {
    return u_ptr<ActiveItem>();
}

u_ptr<ActiveItem> Factory::createActiveItem(Biome biome) {
    return u_ptr<ActiveItem>();
}

u_ptr<PassiveItem> Factory::createPassiveItem(PassiveItemType) {
    return u_ptr<PassiveItem>();
}

u_ptr<PassiveItem> Factory::createPassiveItem(Biome biome) {
    return u_ptr<PassiveItem>();
}

u_ptr<QuestItem> Factory::createQuestItem(QuestItemType) {
    return u_ptr<QuestItem>();
}

u_ptr<MeleeWeapon> Factory::createMeleeWeapon(MeleeWeaponType) {
    return u_ptr<MeleeWeapon>();
}

u_ptr<MeleeWeapon> Factory::createMeleeWeapon(Biome biome) {
    return u_ptr<MeleeWeapon>();
}

u_ptr<RangedWeapon> Factory::createRangedWeapon(RangedWeaponType) {
    return u_ptr<RangedWeapon>();
}

u_ptr<RangedWeapon> Factory::createRangedWeapon(Biome biome) {
    return u_ptr<RangedWeapon>();
}
