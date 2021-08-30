#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <SDL2/SDL.h>
#include <functional>
#include <list>

typedef struct {
    unsigned int event;
    unsigned int subEvent;
} Signature;

class Observer {
public:
    Observer(std::list<Signature> signatures);
    virtual void update(const SDL_Event* event) = 0;
    virtual ~Observer();

private:
    std::list<Signature> signatures;
    std::list<SDL_Event> buffer;
    
    void append();
    void release();
};

#endif //GAME_OBSERVER_H
