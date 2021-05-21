#include "Input.h"
#include "Engine.h"

Input &Input::getInstance() {
    static Input instance;
    return instance;
}

Input::Input() : keyState(SDL_GetKeyboardState(NULL)) {}

void Input::update() {
    SDL_PumpEvents();
}

