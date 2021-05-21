#ifndef GAME_KEYNOTIFIER_H
#define GAME_KEYNOTIFIER_H


#include <SDL2/SDL_scancode.h>
#include <map>
#include "KeyObserver.h"

class KeyNotifier {
private:
    std::multimap<SDL_Scancode, KeyObserver&> keyObservers;
public:
    void append(KeyObserver& keyObserver, SDL_Scancode scancode);
    void release(KeyObserver& keyObserver, SDL_Scancode scancode);
};


#endif //GAME_KEYNOTIFIER_H
