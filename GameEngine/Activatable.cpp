#include "Activatable.h"

const bool& Activatable::isActive() const {
    return active;
}

void Activatable::toggle() {
    active = !active;
}

void Activatable::toggle(const bool& status) {
    active = status;
}
