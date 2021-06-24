#include "Engine.h"
#include "Collision.h"
#include "Utility.h"
#include <iostream>
#include <future>
#include <functional>
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

Engine::Engine(const std::string& title, const int& x, const int& y, const int& width, const int& height, const bool& fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    running = false;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
        if (window) {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                int w = 0;
                int h = 0;
                SDL_GetWindowSize(window, &w, &h);
                camera = {0, 0, w, h};
                running = true;
            }
        }
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

Engine& Engine::getInstance(const std::string& title, const int& x, const int& y, const int& width, const int& height, const bool& fullscreen)
{
    static Engine instance(title, x, y, width, height, fullscreen);
    return instance;
}

void Engine::update() {
    std::list<std::future<void>> asyncCalls;
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++){
        asyncCalls.push_back(std::async(std::launch::async, &Manager::flush, &iter->second));
    }
    for(std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++) {
        asyncCalls.push_back(std::async(std::launch::async, &Manager::update, &iter->second));
    }
    for(std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
    ::collisionUpdate(managers);
}

void Engine::render() {
    SDL_RenderClear(renderer); //clean the previous render buffer

    for(std::unordered_map<std::string, Manager>::iterator iter = managers.begin(); iter != managers.end(); iter++){
        iter->second.draw(); //we use second as a reference to the manager in the iter map to call the method to render the entities
    }
}

bool Engine::drawTexture(const std::string& texturePath, const SDL_Rect& src, const SDL_Rect& dest, const SDL_RendererFlip& flip) {
    bool result = false;
    if (SDL_Texture* texture = IMG_LoadTexture(renderer, texturePath.c_str())) {
        SDL_RenderCopyEx(renderer, texture, &src, &dest, NULL, NULL, flip); //the nulls are because we are not implementing a sprite rotation but a flip
        SDL_DestroyTexture(texture);
        result = true;
    }
    return result;
}

bool Engine::drawText(const std::string& fontPath, const int& size, const std::string& text, const SDL_Color& color, const SDL_Rect& src, const SDL_Rect& dest) {
    bool result = false;
    if(TTF_Font* font = TTF_OpenFont(fontPath.c_str(), size)) {
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_RenderCopyEx(renderer, texture, &src, &dest, NULL, NULL, SDL_FLIP_NONE);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        result = true;
    }
    return result;
}



void Engine::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}

const bool& Engine::isRunning() {
    return running;
}

void Engine::quit() {
    running = false;
}

const int& Engine::getScale(){
    return scale;
}

SDL_Renderer* Engine::getRenderer() {
    return renderer;
}

SDL_Rect& Engine::getCamera() {
    return camera;
}

bool Engine::addManager(const std::string &name, const unsigned int& priority) {
    bool result = managers.emplace(name, Manager(priority)).second;
    if(result){
        sequence.push_front(name);
    }
    return result;
}

Manager & Engine::getManager(const std::string& name) {
    std::unordered_map<std::string, Manager>::iterator result = managers.find(name);
    if (result == managers.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map\"");
    }
    return result->second;
}

bool Engine::compare(const std::string& prev, const std::string& next) {
    return managers.find(prev)->second.getPriority() > managers.find(next)->second.getPriority();
}

void Engine::refreshSequence() {
    bubble_sort(sequence.begin(), sequence.end(), this);
}

bool Engine::removeManager(const std::string& name) {
    bool result = managers.erase(name);
    if(result){
        std::list<std::string>::iterator iter;
        for(iter = sequence.begin(); name != *iter && iter != sequence.end(); iter++) {}
        sequence.erase(iter);
    }
    return result;
}

