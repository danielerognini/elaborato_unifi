#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <unordered_map>
#include <list>
#include "ECS/Manager.h"
#include "SDL2/SDL.h"

class Engine{
private:
    static std::unordered_map<std::string, Manager> managers;
    static std::list<std::string> sequence;

    static SDL_Renderer *renderer; //Because we plan to use always the same renderer it is more convenient to make it static and reference this instead of passing a pointer everytime
    //static SDL_Event event; //create an SDL_Event variable where we are going to poll SDL events into (we want to make it static so that we can access it from anywhere)

    static bool running;
    static SDL_Rect camera;

    Engine(const char* title, int x, int y, int width, int height, bool fullscreen);
    static SDL_Window *window;

    static int scale;

    static bool compare(std::string prev, std::string next);

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

    static bool addManager(std::string name);
    static Manager& getManager(std::string name);
    static bool removeManager(std::string name);

    static void refreshSequence();
};


#endif //GAME_ENGINE_H
