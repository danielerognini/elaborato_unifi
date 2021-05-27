#ifndef GAME_KEYNOTIFIER_H
#define GAME_KEYNOTIFIER_H

#include <SDL2/SDL_keycode.h>
#include <map>
#include "KeyObserver.h"

class KeyNotifier {
private:
    std::multimap<SDL_Keycode, KeyObserver&> keyObservers;

public:
    virtual ~KeyNotifier() = 0;
    void append(KeyObserver& keyObserver, SDL_Keycode keycode);
    void release(KeyObserver& keyObserver, SDL_Keycode keycode);
    void notify(SDL_Keycode keycode);
};


#endif //GAME_KEYNOTIFIER_H
