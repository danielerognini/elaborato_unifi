#include "Input.h"
#include "Engine.h"

Input &Input::getInstance() {
    static Input instance;
    return instance;
}

Input::Input() {

}

void Input::update() {
    while(SDL_PollEvent(&event)) {
        notify(event.key.keysym.sym);
        //TODO: handle all the other non-keyboard events (such as: mouse events, joystick events...)
    }
}

