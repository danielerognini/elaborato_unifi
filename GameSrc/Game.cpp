#include <iostream>

#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include "Engine.h"
#include "Input.h"

int main()
{
    int maxFPS = 60; //the maximum fps our game will run at //not a const cause we may want the user to be able to change this
    int frameDelay = 1000 / maxFPS; //it is the max time we have between each frame //not a const cause if maxFPS changes we want this variable to adapt

    unsigned int frameStart;
    int frameTime;

    Engine& engine = Engine::getInstance("GameEngine_alpha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 600, false);

    Input& input = Input::getInstance();

    //while the game is running
    while (engine.isRunning())
    {
        //getting current framerate
        frameStart = SDL_GetTicks();

        //handle player input and other events
        input.update();

        //update all objects
        engine.update();

        //render changes to display
        engine.render();

        //limiting framerates
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }

    return 0;
}
