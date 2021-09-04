#include "Door.h"

void Door::Lock() {
    locked = true;
}

void Door::Unlock() {
    locked = false;
}

bool Door::isLocked() {
    return locked;
}
