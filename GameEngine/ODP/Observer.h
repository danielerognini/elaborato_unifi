#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <SDL2/SDL.h>
#include <functional>
#include <list>
#include <map>
#include "Activatable.h"

typedef struct {
    unsigned int event;
    unsigned int subEvent;
} Signature;

typedef struct {
    SDL_Event event;
    Signature signature;
} EventAlert;

class Observer : public Activatable {
public:
    Observer(const std::map<std::string, Signature>& signatures, std::function<void()> function);
    ~Observer() override = default;
    void pushEvent(EventAlert eventAlert);
    virtual void update();
    const Signature& getSignature(const std::string& name) const;
    bool modifySignature(const std::string& name, Signature signature);

private:
    std::unordered_map<std::string, Signature> signatures;
    std::list<EventAlert> buffer;
    std::function<void()> function;
    
    void append(const Signature& signature);
    void release(const Signature& signature);
};

#endif //GAME_OBSERVER_H
