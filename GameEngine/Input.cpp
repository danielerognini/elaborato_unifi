#include <fstream>
#include <bitset>
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
        SDL_WindowEvent
        switch (event) {
            case:
                break;
            case:
                break;
            case:
                break;
            case:
                break;
            case:
                break;
            case:
                break;
        }
    }
    notify();
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

void Input::notify() {
    std::list<std::string> controls = matchControl();
    for(std::list<std::string>::iterator iter = controls.begin(); iter != controls.end(); iter++) {
        for(std::pair<std::multimap<std::string, ControlObserver*>::iterator, std::multimap<std::string, ControlObserver*>::iterator> subIter = controlObservers.equal_range(*iter); subIter.first != subIter.second; subIter.first++) {
            subIter.first->second->update();
        }
    }
}

void Input::append(ControlObserver* controlObserver, std::string control) {
    controlObservers.emplace(control, controlObserver);
}

void Input::release(ControlObserver *controlObserver) {
    std::multimap<std::string, ControlObserver*>::iterator iter;
    for(iter = controlObservers.begin(); iter != controlObservers.end() && iter->second != controlObserver; iter++) {}
    controlObservers.erase(iter);
}

std::list<std::string> Input::matchControl() {
    std::map<std::string, std::vector<bool>> matchBuffer;
    std::list<std::string> distinctBuffer;
    std::list<std::string> controls;
    int i;

    for(std::map<std::list<std::string>, std::string>::iterator iter = controlsMap.begin(); iter != controlsMap.end(); iter++) {
        matchBuffer.emplace(iter->second, std::vector<bool>(buffer.size(), false));
        i = 0;
        for(std::list<std::string>::iterator subIter = buffer.begin(); subIter != buffer.end(); subIter++) {
            for(auto subSubIter = iter->first.begin(); subSubIter != iter->first.end(); subSubIter++) {
                if(*subIter == *subSubIter){
                    matchBuffer[iter->second][i] = true;
                }
            }
            i++;
        }
    }

    int keyNum;
    for(i = 0; i < buffer.size(); i++) {
        keyNum = 1;
        for(std::map<std::string, std::vector<bool>>::iterator iter = matchBuffer.begin(); iter != matchBuffer.end(); iter++) {
            if(iter->second[i]) {
                int count = 0;
                for(std::vector<bool>::iterator subIter = iter->second.begin(); subIter != iter->second.end(); subIter++) {
                    if(*subIter) {
                        count++;
                    }
                }
                if(count > keyNum) {
                    keyNum = count;
                    distinctBuffer.clear();
                }
                distinctBuffer.emplace_back(iter->first);
                matchBuffer.erase(iter);
            }
        }
        while(distinctBuffer.size()) {
            controls.emplace_back(distinctBuffer.front());
            distinctBuffer.pop_front();
        }
    }

    return controls;
}
