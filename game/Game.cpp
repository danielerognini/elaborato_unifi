#include <iostream>
#include "SDL2/SDL.h"
#include "Engine.h"
#include "odp/Input.h"
#include "Scheduler.h"

int main() {
    Engine& engine = Engine::getInstance("GameEngine_alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 600, false);
    
    Input& input = Input::getInstance();
    
    Scheduler& scheduler = Scheduler::getInstance();
    
    unsigned int frameDelay;
    
    //while the game is running
    while (engine.isRunning()) {
        //getting current framerate
        engine.updateFrameStart();
        
        //manage all objects and flush unused observers
        scheduler.update();
        
        //handle player input and other events
        input.update();
        
        //update all objects
        engine.update();
    
        //render changes to display
        engine.render();
    
        //limiting framerates
        frameDelay = engine.getMinFrameTime() - (SDL_GetTicks() - engine.getFrameStart());
        if (frameDelay > 0) {
            SDL_Delay(frameDelay);
        }
        if (engine.getFrameStart() >= 5000) {
            engine.quit();
        }
    }

    return 0;
}
/*
int main() {
    std::cout << "w: " << SDLK_w << std::endl;
    std::cout << "a: " << SDLK_a << std::endl;
    std::cout << "s: " << SDLK_s << std::endl;
    std::cout << "d: " << SDLK_d << std::endl;
    std::cout << "e: " << SDLK_e << std::endl;
    std::cout << "space: " << SDLK_SPACE << std::endl;
    std::cout << "^: " << SDLK_UP << std::endl;
    std::cout << "v: " << SDLK_DOWN << std::endl;
    std::cout << "<: " << SDLK_LEFT << std::endl;
    std::cout << ">: " << SDLK_RIGHT << std::endl;
    std::cout << "mousebuttondown: " << SDL_MOUSEBUTTONDOWN << std::endl;
    std::cout << "left-click: " << SDL_BUTTON_LEFT << std::endl;
    std::cout << "enter: " << SDLK_KP_ENTER << std::endl;
    std::cout << "userevent: " << SDL_USEREVENT << std::endl;
    std::cout << "esc: " << SDLK_ESCAPE << std::endl;
    std::cout << "shift: " << SDLK_LSHIFT << std::endl;
    
    return 0;
}
*/