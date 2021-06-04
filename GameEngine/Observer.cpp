#include "Observer.h"
#include "Input.h"

void Observer::append() {
    Input::getInstance().append(this);
}

void Observer::release() {
    Input::getInstance().release(this);
}

Observer::~Observer() {
    release();
}
