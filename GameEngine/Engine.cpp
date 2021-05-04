#include "Engine.h"
#include "Collision.h"
#include "Utility.h"
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

bool Engine::addManager(std::string name) {
    bool result = managers.emplace(name, Manager()).second;
    if(result){
        sequence.push_front(name);
    }
    return result;
}

Manager &Engine::getManager(std::string name) {
    return managers.find(name)->second;
}

bool Engine::compare(std::string prev, std::string next) {
    return managers.find(prev)->second.getPriority() < managers.find(next)->second.getPriority();
}

void Engine::refreshSequence() {
    bubble_sort(sequence.begin(), sequence.end(), Engine::compare);
}

bool Engine::removeManager(std::string name) {
    bool result = managers.erase(name);
    if(result){
        std::list<std::string>::iterator iter;
        for(iter = sequence.begin(); name != *iter && iter != sequence.end(); iter++) {}
        sequence.erase(iter);
    }
    return result;
}

