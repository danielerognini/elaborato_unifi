#include "Observer.h"
#include "Input.h"

void Observer::append() {
    Input::getInstance().append(this, <#initializer#>, <#initializer#>);
}

void Observer::release() {
    Input::getInstance().release(this, <#initializer#>, <#initializer#>);
}

Observer::~Observer() {
    release();
}
