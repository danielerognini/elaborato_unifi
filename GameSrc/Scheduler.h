#ifndef GAME_SCHEDULER_H
#define GAME_SCHEDULER_H

#include <memory>
#include "Utility.h"
#include "ODP/Observer.h"

class Scheduler {
public:
    static Scheduler& getInstance();
    ~Scheduler() = default;
    void update();
    
    void addObserver(Observer* observer);
    void remapEvent(const std::string& event, Signature signature);

private:
    std::unordered_map<std::string, Signature> events;
    std::list<u_ptr<Observer>> observers;
    Scheduler();
};


#endif //GAME_SCHEDULER_H
