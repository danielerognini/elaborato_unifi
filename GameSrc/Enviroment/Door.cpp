#include "Door.h"

void Door::lock() {
    locked = true;
}

void Door::unlock() {
    locked = false;
}

bool Door::isLocked() {
    return locked;
}
