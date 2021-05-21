#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <memory>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "KeyObserver.h"

class Input {
public:
    Input& getInstance();
    void update();

private:
    Input();
    std::unique_ptr<const Uint8> keyState;
};


#endif //GAME_INPUT_H
