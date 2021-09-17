#include "Door.h"

Door::Door(const std::string &texturePath, Room *room, Room *hallway, Border doorStep, Direction pushDirection) : Entity(texturePath, false), room(room), hallway(hallway), pushDirection(pushDirection), doorStep(doorStep) {}

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
        /*
        if(!room->isDiscovered()) {
            //TODO: push the player trough the door
            if(hallway->getLayer("players").begin() != hallway->getLayer("players").end() && hallway->getLayer("players").begin()->second.get() == &externalEntity) {
                //TODO: pass the player to the room's manager
            }
            else if(room->getLayer("players").begin() != room->getLayer("players").end() && room->getLayer("players").begin()->second.get() == &externalEntity) {
                //TODO: pass the player to the hallway's manager
            }
            lock();
        }
        else {
            if(hallway->getLayer("players").begin() != hallway->getLayer("players").end() && hallway->getLayer("players").begin()->second.get() == &externalEntity) {
                //TODO: pass the player to the room's manager
            }
            else if(room->getLayer("players").begin() != room->getLayer("players").end() && room->getLayer("players").begin()->second.get() == &externalEntity) {
                //TODO: pass the player to the hallway's manager
            }
            unlock();
        }
        */
        getSprite().setCurrentAnimation("open");
    }
}
