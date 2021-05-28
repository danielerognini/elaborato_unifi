#include "ControlObserver.h"
#include "Input.h"

ControlObserver::~ControlObserver() {
    release();
}

ControlObserver::ControlObserver(std::string control) {
    Input::getInstance().append(this, control)
}

void ControlObserver::release() {
    Input::getInstance().release(this);
}