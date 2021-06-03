#ifndef GAME_CONTROLOBSERVER_H
#define GAME_CONTROLOBSERVER_H


#include <functional>
#include "ECS/Entity.h"

class ControlObserver {
public:
    void update();

    ControlObserver(std::string control, std::function<void(Entity*)>);
    ~ControlObserver();
    void release();
private:
    Entity* entity;
    std::function<void(Entity*)> function;
};


#endif //GAME_CONTROLOBSERVER_H
