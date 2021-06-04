#ifndef GAME_CONTROLOBSERVER_H
#define GAME_CONTROLOBSERVER_H

#include "Observer.h"
#include <functional>
#include "ECS/Entity.h"

class ControlObserver : public Observer {
public:
    void update() override;

    ControlObserver(Entity* entity, std::function<void(Entity*)> function);
    ~ControlObserver();

private:
    Entity* entity;
    std::function<void(Entity*)> function;
};


#endif //GAME_CONTROLOBSERVER_H
