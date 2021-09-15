#ifndef GAME_SCHEDULER_H
#define GAME_SCHEDULER_H

#include <memory>
#include "ODP/Observer.h"

class Scheduler {
public:
    Scheduler();
    ~Scheduler() = default;
    void update();

private:
    std::list<std::unique_ptr<Observer>> observers;
};


#endif //GAME_SCHEDULER_H
