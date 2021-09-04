#include "Chasm.h"

Chasm::Chasm(bool solid, bool active) : CollisionArea(solid, active) {

}

void Chasm::resolveCollision(const Entity &externalEntity, const Vector2D &collisionVector) {
    //TODO: trigger the creature falling animation
}

