#ifndef GAME_SCHEDULER_H
#define GAME_SCHEDULER_H

#include <memory>
#include "Utility.h"
#include "odp/Observer.h"

class Scheduler {
public:
    static Scheduler& getInstance();
    Scheduler(const Scheduler& scheduler) = delete;
    bool operator=(const Scheduler& scheduler) = delete;
    ~Scheduler() = default;
    void update();
    
    void addObserver(Observer* observer);
    void remapEvent(const std::string& event, Signature signature);
    Signature getSignature(const std::string& event);

private:
    std::unordered_map<std::string, Signature> events;
    std::list<u_ptr<Observer>> observers;
    Scheduler();
};


#endif //GAME_SCHEDULER_H
