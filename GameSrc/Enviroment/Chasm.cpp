#include "Chasm.h"

Chasm::Chasm(bool solid) : CollisionArea(solid) {
}

void Chasm::resolveCollision(const Entity &externalEntity, const Vector2D &collisionVector) {
    //TODO: trigger the creature falling animation
}

