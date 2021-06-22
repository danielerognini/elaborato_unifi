#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <future>
#include <memory>
#include <unordered_map>
#include <list>
#include <map>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "ControlObserver.h"
#include "Observer.h"

class Input{
public:
    static Input& getInstance();
    void update();

    void append(Observer* observer);
    void release(Observer* observer);


private:
    Input();
    SDL_Event event;

    void notify();
    void execute();

    std::list<Observer*> observers;

    std::list<std::future<void>> asyncCalls;
};


#endif //GAME_INPUT_H
