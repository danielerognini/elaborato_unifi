#include <iostream>

#include "SDL2/SDL.h"
#include "Engine.h"
#include "ODP/Input.h"

#define SDL_MAIN_HANDLED

int main()
{
    Engine& engine = Engine::getInstance("GameEngine_alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 600, false);

    Input& input = Input::getInstance();

    unsigned int frameDelay;

    //while the game is running
    while (engine.isRunning())
    {
        //getting current framerate
        engine.updateFrameStart();

        //handle player input and other events
        input.update();

        //update all objects
        engine.update();

        //render changes to display
        engine.render();

        //limiting framerates
        frameDelay = engine.getMinFrameTime() - (SDL_GetTicks() - engine.getFrameStart());
        if(frameDelay > 0){
            SDL_Delay(frameDelay);
        }
    }

    return 0;
}
