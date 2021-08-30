#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <SDL2/SDL.h>
#include <functional>
#include <list>
#include <queue>

typedef struct {
    unsigned int event;
    unsigned int subEvent;
} Signature;

class Observer {
public:
    explicit Observer(std::list<Signature> signatures);
    void pushEvent(SDL_Event event);
    virtual void update() = 0;
    virtual ~Observer();

private:
    std::list<Signature> signatures;
    std::queue<SDL_Event> buffer;
    
    void append();
    void release();
};

#endif //GAME_OBSERVER_H
