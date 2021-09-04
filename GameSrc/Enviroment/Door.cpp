#include "Door.h"
#include "../Room.h"

void Door::lock() {
    setSolid(true);
    //TODO: change door animation
}

void Door::unlock() {
    setSolid(false);
    //TODO: change door animation
}

void Door::resolveCollision(const Entity &externalEntity, const Vector2D &collisionVector) {
    if(isSolid()){
        Entity::resolveCollision(externalEntity, collisionVector);
    }
    else{
        if(!room->isDiscovered()) {
            //TODO: push the player trough the door
            lock();
        }
        else {
            unlock();
        }
    }
}
