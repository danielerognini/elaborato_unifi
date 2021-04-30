#include "Engine.h"
#include "Collision.h"
#include <iostream>

Engine::Engine(const char *title, int x, int y, int width, int height, bool fullscreen) {}

Engine& Engine::getInstance(const char* title, int x, int y, int width, int height, bool fullscreen)
{
    static Engine instance(title, x, y, width, height, fullscreen);
    return instance;
}

void Engine::update() {
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++){
        iter->second.flush(); //we use second as a reference to the manager in the iter map to flush inactive entities
        iter->second.update(); //we use second as a reference to the manager in the iter map to update the active entities
    }
    Collision::update(managers);
}

void Engine::render() {
    SDL_RenderClear(renderer); //clean the previous render buffer

    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++){
        iter->second.draw(); //we use second as a reference to the manager in the iter map to call the method to render the entities
    }
}

void Engine::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

bool Engine::isRunning() const {
    return running;
}

void Engine::quit() {
    running = false;
}

int Engine::getScale(){
    return scale;
}

SDL_Renderer* Engine::getRenderer() {
    return renderer;
}

SDL_Rect& Engine::getCamera() {
    return camera;
}

