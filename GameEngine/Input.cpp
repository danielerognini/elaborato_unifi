#include <fstream>
#include <bitset>
#include <future>
#include "Input.h"
#include "Engine.h"

Input& Input::getInstance() {
    static Input instance;
    return instance;
}

Input::Input() {
}

void Input::update() {
    while (SDL_PollEvent(&event)) {
        notify();
    }
    execute();
}

void Input::notify() {
    for (std::list<Observer*>::iterator iter = observers.begin(); iter != observers.end(); iter++) {
        asyncCalls.push_back(std::async(std::launch::async, &Observer::update, *iter, &event));
    }
}

void Input::append(Observer* observer) {
    observers.emplace_back(observer);
}

void Input::release(Observer* observer) {
    std::list<Observer*>::iterator iter;
    for (iter = observers.begin(); iter != observers.end() && *iter != observer; iter++) {}
    observers.erase(iter);
}

void Input::execute() {
    for (std::list<std::future<void>>::iterator iter = asyncCalls.begin(); iter != asyncCalls.end(); iter++) {
        iter->get();
    }
    asyncCalls.clear();
    for (std::list<Observer*>::iterator iter = observers.begin(); iter != observers.end(); iter++) {
        (*iter)->update(nullptr);
    }
}
