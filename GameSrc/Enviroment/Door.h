#ifndef GAME_DOOR_H
#define GAME_DOOR_H

#include <ECS/Entity.h>

class Door : public Entity{
public:
    void Lock();
    void Unlock();
    bool isLocked();
private:
    bool locked;
};


#endif //GAME_DOOR_H
