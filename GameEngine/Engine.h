#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <unordered_map>
#include <list>
#include "ECS/Manager.h"
#include "SDL2/SDL.h"

class Engine{
public:
    //GameEngine();
    static Engine& getInstance(const std::string& title, const int& x, const int& y, const int& width, const int& height, const bool& fullscreen);
    ~Engine();

    static void update();
    static void render();
    static bool drawTexture(const std::string& texturePath, const SDL_Rect& src, const SDL_Rect& dest, const SDL_RendererFlip& flip);
    static void clean();

    static const bool& isRunning();
    static void quit();

    static SDL_Renderer* getRenderer();

    static const int& getScale();
    static SDL_Rect& getCamera();

    static bool addManager(const std::string& name);
    static const Manager& getManager(const std::string& name);
    static bool removeManager(const std::string& name);

    static void refreshSequence();

private:
    static std::unordered_map<std::string, Manager> managers;
    static std::list<std::string> sequence;

    Engine(const std::string& title, const int& x, const int& y, const int& width, const int& height, const bool& fullscreen);
    static SDL_Window* window;
    static SDL_Renderer* renderer; //Because we plan to use always the same renderer it is more convenient to make it static and reference this instead of passing a pointer everytime
    //static SDL_Event event; //create an SDL_Event variable where we are going to poll SDL events into (we want to make it static so that we can access it from anywhere)
    static SDL_Rect camera;
    static bool running;

    static int scale;

    static bool compare(const std::string& prev, const std::string& next);
};


#endif //GAME_ENGINE_H
