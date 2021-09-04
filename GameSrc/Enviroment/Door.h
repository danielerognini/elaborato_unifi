#ifndef GAME_DOOR_H
#define GAME_DOOR_H

#include <ECS/Entity.h>
#include "../Room.h"

class Door : public Entity{
public:
    void lock();
    void unlock();
    void resolveCollision(const Entity& externalEntity, const Vector2D& collisionVector) override;
private:
    std::shared_ptr<Room> room;
    std::shared_ptr<Room> hallway;
};


#endif //GAME_DOOR_H
