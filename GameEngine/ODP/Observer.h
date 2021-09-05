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
    Observer(const std::unordered_map<std::string, Signature>& signatures, std::function<void()> function);
    virtual ~Observer() = 0;
    void pushEvent(EventAlert eventAlert);
    virtual void update();
    bool addSignature(const std::string& name, Signature signature);
    bool removeSignature(const std::string& name);
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
