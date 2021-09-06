#include "Scheduler.h"

Scheduler::Scheduler() {
}

void Scheduler::flush() {
    for (auto iter = observers.begin(); iter != observers.end(); iter++) {
        /* TODO: fix.
        if (!(*iter)->isActive()) {
            observers.erase(iter);
        }
        */
    }
}
