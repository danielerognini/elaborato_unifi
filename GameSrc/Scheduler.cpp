#include "Scheduler.h"

Scheduler::Scheduler() {
}

void Scheduler::update() {
    for (auto iter = observers.begin(); iter != observers.end(); iter++) {
        if (!(*iter)->hasTarget()) {
            observers.erase(iter);
        }
    }
}
