#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H


#include <SDL2/SDL.h>

class Observer {
public:
    void update(const SDL_Event* event);
};


#endif //GAME_OBSERVER_H
