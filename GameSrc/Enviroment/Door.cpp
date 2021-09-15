#include "Door.h"
#include "../Room.h"

Door::Door(const std::string &texturePath, Room *room, Room *hallway, Direction pushDirection) : Entity(texturePath, false), room(room), hallway(hallway), pushDirection(pushDirection) {}

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
