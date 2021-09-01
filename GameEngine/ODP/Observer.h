#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <SDL2/SDL.h>
#include <functional>
#include <list>

typedef struct {
    unsigned int event;
    unsigned int subEvent;
} Signature;

typedef struct {
    SDL_Event event;
    Signature signature;
} EventAlert;

class Observer {
public:
    explicit Observer(std::unordered_map<std::string, Signature> signatures);
    virtual ~Observer();
    void pushEvent(EventAlert eventAlert);
    virtual void update() = 0;
    bool addSignature(std::string name, Signature signature);
    bool removeSignature(std::string name);
    const Signature& getSignature(std::string name) const;
    bool modifySignature(std::string name, Signature signature);

private:
    std::unordered_map<std::string, Signature> signatures;
    std::list<EventAlert> buffer;
    
    void append(const Signature& signature);
    void release(const Signature& signature);
};

#endif //GAME_OBSERVER_H
