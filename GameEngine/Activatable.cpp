#include "Activatable.h"

bool Activatable::isActive() const {
    return active;
}

void Activatable::toggle() {
    active = !active;
}

void Activatable::toggle(bool status) {
    active = status;
}

Activatable::~Activatable() {}

Activatable::Activatable(bool active) : active(active) {}
