#include "Observer.h"

#include <utility>
#include "Input.h"

void Observer::append() {
    for (auto& signature: signatures) {
        Input::getInstance().append(this, signature.event, signature.subEvent);
    }
}

void Observer::release() {
    for (auto& signature: signatures) {
        Input::getInstance().release(this, signature.event, signature.subEvent);
    }
}

Observer::~Observer() {
    release();
}

Observer::Observer(std::list<Signature> signatures) {
    this->signatures = std::move(signatures);
    append();
}

void Observer::pushEvent(const SDL_Event event) {
    buffer.push(event);
}
