#include "KeyNotifier.h"

void KeyNotifier::append(KeyObserver &keyObserver, SDL_Keycode keycode) {
    keyObservers.emplace(keycode, keyObserver);
}

void KeyNotifier::release(KeyObserver &keyObserver, SDL_Keycode keycode) {
    std::multimap<SDL_Keycode, KeyObserver&>::iterator iter = keyObservers.find(keycode);
    while(&(iter++)->second != &keyObserver) {}
    keyObservers.erase(iter);
}

void KeyNotifier::notify(SDL_Keycode keycode) {
    std::pair<std::multimap<SDL_Keycode, KeyObserver&>::iterator, std::multimap<SDL_Keycode, KeyObserver&>::iterator> iterPair = keyObservers.equal_range(keycode);
    for(std::multimap<SDL_Keycode, KeyObserver&>::iterator iter = iterPair.first; iter != iterPair.second; iter++) {
        iter->second.update();
    }
}
