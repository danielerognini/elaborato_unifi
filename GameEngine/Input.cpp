#include <fstream>
#include "Input.h"
#include "Engine.h"

Input &Input::getInstance() {
    static Input instance;
    return instance;
}

Input::Input() {

}

void Input::update() {
    while(SDL_PollEvent(&event)) {
        buffer.emplace_back(SDL_GetKeyName(event.key.keysym.sym));
    }
    notify(buffer);
}

void Input::loadControlsMap(const std::string &filePath) {
    std::ifstream file(filePath);
    std::string line;
    if(file.is_open()) {
        while (std::getline(file, line)) {
            std::pair<std::list<std::string>, std::string> control = parseLine(line);
            controlsMap.emplace(control.first, control.second);
        }
    }
}

std::pair<std::list<std::string>, std::string> Input::parseLine(std::string line) {
    //an example of a line in the controls manager is: "w d -> walk_up_right"
    std::string parseBuffer = "";
    std::string control;
    std::list<std::string> listBuffer;
    bool arrow = false;
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == ' ') {
            if(parseBuffer.length()) {
                if(parseBuffer.compare("->")) {
                    arrow = true;
                }
                else if(arrow) {
                    control = parseBuffer;
                }
                if(!arrow) {
                    listBuffer.emplace_back(parseBuffer);
                }
                parseBuffer = "";
            }
        }
        else{
            parseBuffer += line[i];
        }
    }
    return std::make_pair(listBuffer, control);
}

void Input::notify(std::list<std::string> list) {
    //TODO: implement notification
}

void Input::append(ControlObserver *controlObserver, std::string control) {
    controlObservers.emplace(control, controlObserver);
}

void Input::release(ControlObserver *controlObserver) {
    std::multimap<std::string, ControlObserver*>::iterator iter;
    for(iter = controlObservers.begin(); iter != controlObservers.end() && iter->second != controlObserver; iter++) {}
    controlObservers.erase(iter);
}
