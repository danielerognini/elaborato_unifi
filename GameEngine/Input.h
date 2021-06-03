#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <memory>
#include <unordered_map>
#include <list>
#include <map>
#include "SDL2/SDL.h"
#include "Vector2D.h"
#include "ControlObserver.h"

class Input{
public:
    static Input& getInstance();
    void loadControlsMap(const std::string& filePath);
    void update();

    void append(ControlObserver* controlObserver, std::string control);

    void release(ControlObserver* controlObserver);

private:
    Input();
    SDL_Event event;
    std::list<std::string> buffer;
    std::map<std::list<std::string>, std::string> controlsMap;

    std::pair<std::list<std::string>, std::string> parseLine(std::string basicString);

    void notify();
    std::list<std::string> matchControl();

    std::multimap<std::string, ControlObserver*> controlObservers;
};


#endif //GAME_INPUT_H
