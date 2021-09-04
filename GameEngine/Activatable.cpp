#include "Activatable.h"

bool Activatable::isActive() const {
    return active;
}

void Activatable::enable() {
    active = true;
}

void Activatable::disable() {
    active = false;
}

Activatable::Activatable(bool active) : active(active) {}

