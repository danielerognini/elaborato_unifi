#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <SDL2/SDL.h>
#include <functional>

class Observer {
public:
    virtual void update(const SDL_Event* event) = 0;
    virtual ~Observer();
    
    void append();
    void release();
};

#endif //GAME_OBSERVER_H
