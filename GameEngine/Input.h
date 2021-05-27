#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <memory>
#include <unordered_map>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "KeyNotifier.h"

class Input : public KeyNotifier{
public:
    Input& getInstance();
    void update();

private:
    Input();
    SDL_Event event;
};


#endif //GAME_INPUT_H
