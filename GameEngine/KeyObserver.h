#ifndef GAME_KEYOBSERVER_H
#define GAME_KEYOBSERVER_H


#include <SDL2/SDL_scancode.h>
#include "KeyNotifier.h"

class KeyObserver {
public:
    void append(SDL_Scancode scancode);
    void release(SDL_Scancode scancode);

    virtual void update() = 0;
    virtual ~KeyObserver();
private:
    KeyNotifier& keyNotifier;
};


#endif //GAME_KEYOBSERVER_H
