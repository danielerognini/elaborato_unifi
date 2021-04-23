#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <map>
#include "Manager.h"
#include "SDL.h"

class Engine {
private:
    std::map<std::string, Manager> managers;

    static SDL_Renderer *renderer; //Because we plan to use always the same renderer it is more convenient to make it static and reference this instead of passing a pointer everytime
    //static SDL_Event event; //create an SDL_Event variable where we are going to poll SDL events into (we want to make it static so that we can access it from anywhere)

    static bool running;
    static SDL_Rect camera;
    static Manager& manager;

    Engine(const char* title, int x, int y, int width, int height, bool fullscreen);
    SDL_Window *window;

    static int& scale;

public:
    //GameEngine();
    static Engine& getInstance(const char* title, int x, int y, int width, int height, bool fullscreen);
    ~Engine();

    void update();
    void render();
    void clean();

    bool isRunning() const;
    void quit();

    static SDL_Renderer * getRenderer();

    static int getScale();
    static SDL_Rect & getCamera();
};


#endif //GAME_ENGINE_H
