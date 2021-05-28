#ifndef GAME_CONTROLOBSERVER_H
#define GAME_CONTROLOBSERVER_H


#include "ECS/Entity.h"

class ControlObserver {
public:
    virtual void update() = 0;

    ControlObserver(std::string control);
    virtual ~ControlObserver();
    void release();
private:
    Entity* entity;
};


#endif //GAME_CONTROLOBSERVER_H
