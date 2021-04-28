#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include "SDL2/SDL.h"

class Input {
public:
    void scanInput();

private:
    SDL_Event event;

    void keyDown(SDL_Event& event);
};


#endif //GAME_INPUT_H
