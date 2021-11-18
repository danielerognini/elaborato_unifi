#ifndef GAME_DOOR_H
#define GAME_DOOR_H

#include <ecs/Entity.h>
#include "../Room.h"

class Door : public Entity{
    /*
public:
    Door(const std::string& texturePath, Room* room, Room* hallway, Border doorStep, Direction pushDirection);
    void lock();
    void unlock();
    void resolveCollision(Entity* externalEntity, const Vector2D& collisionVector) override;
private:
    Room* room;
    Room* hallway;

    Border doorStep;

    Direction pushDirection; //Hallway to room
     */
};


#endif //GAME_DOOR_H
