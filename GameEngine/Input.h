#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <future>
#include <memory>
#include <list>
#include <array>
#include <map>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "ControlObserver.h"
#include "Observer.h"

typedef;

typedef struct {
    std::function<int()> findIndex;
    std::multimap<int, Observer*> subEvents;
} EventWrapper;

class Input {
public:
    static Input& getInstance();
    void update();
    
    void append(Observer* observer, const int& type, const int& subType);
    void release(Observer* observer, const int& type, const int& subType);

private:
    Input();
    SDL_Event event;
    std::array<EventWrapper, 47> events;
    std::pair<std::multimap<int, Observer*>::iterator, std::multimap<int, Observer*>::iterator> observers;
    
    void notify();
    void execute();
    
    //std::list<Observer*> observers;
    
    std::list<std::future<void>> asyncCalls;
};

#endif //GAME_INPUT_H
