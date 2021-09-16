#include "Activatable.h"

Activatable::Activatable(bool active) : active(active) {}

bool Activatable::isActive() const {
    return active;
}

void Activatable::enable() {
    active = true;
}

void Activatable::disable() {
    active = false;
}

Activatable::~Activatable() {
}

