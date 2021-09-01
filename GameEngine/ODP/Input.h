#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <future>
#include <memory>
#include <list>
#include <array>
#include <map>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "Observer.h"

typedef struct {
    std::function<unsigned int()> findIndex;
    std::multimap<unsigned int, Observer*> subEvents;
} EventWrapper;

class Input {
public:
    static Input& getInstance();
    void update();
    
    void append(Observer* observer, unsigned int type, unsigned int subType);
    void release(Observer* observer, unsigned int type, unsigned int subType);

private:
    Input();
    SDL_Event event;
    std::array<EventWrapper, 47> events;
    std::pair<std::multimap<unsigned int, Observer*>::iterator, std::multimap<unsigned int, Observer*>::iterator> observers;
    
    void notify();
    void execute();
    
    std::list<std::future<void>> asyncCalls;
};

#endif //GAME_INPUT_H
