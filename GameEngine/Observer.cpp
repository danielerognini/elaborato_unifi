#include "Observer.h"

#include <utility>
#include "Input.h"

void Observer::append() {
    for (std::list<Signature>::iterator iter = signatures.begin(); iter != signatures.end(); iter++) {
        Input::getInstance().append(this, iter->event, iter->subEvent);
    }
}

void Observer::release() {
    for (std::list<Signature>::iterator iter = signatures.begin(); iter != signatures.end(); iter++) {
        Input::getInstance().release(this, iter->event, iter->subEvent);
    }
}

Observer::~Observer() {
    release();
}

Observer::Observer(std::list<Signature> signatures) {
    this->signatures = std::move(signatures);
    append();
}
