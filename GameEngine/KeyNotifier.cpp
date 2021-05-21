#include "KeyNotifier.h"

void KeyNotifier::append(KeyObserver &keyObserver, SDL_Scancode scancode) {
    keyObservers.emplace(scancode, keyObserver);
}

void KeyNotifier::release(KeyObserver &keyObserver, SDL_Scancode scancode) {
    std::multimap<SDL_Scancode, KeyObserver&>::iterator iter = keyObservers.find(scancode);
    while(&iter->second != &keyObserver) {}
    keyObservers.erase(iter);
}
