#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <unordered_map>
#include <list>
#include "ECS/Manager.h"
#include "SDL2/SDL.h"

class Engine {
public:
    //GameEngine();
    static Engine& getInstance(const std::string& title = "Title", const int& x = 0, const int& y = 0, const int& width = 1920, const int& height = 1080, const bool& fullscreen = false);
    ~Engine();
    
    void update();
    void render();
    bool drawTexture(const std::string& texturePath, const SDL_Rect& src, const SDL_Rect& dest, const SDL_RendererFlip& flip);
    bool drawText(const std::string& fontPath, const int& size, const std::string& text, const SDL_Color& color, SDL_Rect& src, SDL_Rect& dest);
    void clean();
    
    const bool& isRunning();
    void quit();
    
    SDL_Renderer* getRenderer();
    
    const int& getScale();
    SDL_Rect& getCamera();
    
    bool addManager(const std::string& name, const unsigned int& priority);
    bool removeManager(const std::string& name);
    Manager& getManager(const std::string& name);
    
    void refreshSequence(); //sorts managers by priority using bubble sort
    bool compare(const std::string& prev, const std::string& next);

private:
    std::unordered_map<std::string, Manager> managers;
    std::list<std::string> sequence;
    
    Engine(const std::string& title, const int& x, const int& y, const int& width, const int& height, const bool& fullscreen);
    SDL_Window* window;
    SDL_Renderer* renderer; //Because we plan to use always the same renderer it is more convenient to make it static and reference this instead of passing a pointer everytime
    //static SDL_Event event; //create an SDL_Event variable where we are going to poll SDL events into (we want to make it static so that we can access it from anywhere)
    SDL_Rect camera;
    bool running;
    
    int scale;
};

#endif //GAME_ENGINE_H
