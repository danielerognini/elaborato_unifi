#include <future>
#include "Input.h"
#include "Engine.h"

Input& Input::getInstance() {
    static Input instance;
    return instance;
}

Input::Input() : event(SDL_Event()) {
    std::function<unsigned int()> zero = [&]() { return 0; };
    events[SDL_QUIT].findIndex = zero;
    events[SDL_APP_TERMINATING].findIndex = zero;
    events[SDL_APP_LOWMEMORY].findIndex = zero;
    events[SDL_APP_WILLENTERBACKGROUND].findIndex = zero;
    events[SDL_APP_DIDENTERBACKGROUND].findIndex = zero;
    events[SDL_APP_WILLENTERFOREGROUND].findIndex = zero;
    events[SDL_APP_DIDENTERFOREGROUND].findIndex = zero;
    events[SDL_WINDOWEVENT].findIndex = [&]() { return event.window.event; };
    events[SDL_SYSWMEVENT].findIndex = zero;
    events[SDL_KEYDOWN].findIndex = [&]() { return event.key.keysym.sym; };
    events[SDL_KEYUP].findIndex = [&]() { return event.key.keysym.sym; };
    events[SDL_TEXTEDITING].findIndex = zero;
    events[SDL_TEXTINPUT].findIndex = zero;
    events[SDL_KEYMAPCHANGED].findIndex = zero;
    events[SDL_MOUSEMOTION].findIndex = zero;
    events[SDL_MOUSEBUTTONDOWN].findIndex = [&]() { return event.button.button; };
    events[SDL_MOUSEBUTTONUP].findIndex = [&]() { return event.button.button; };
    events[SDL_MOUSEWHEEL].findIndex = zero;
    events[SDL_JOYAXISMOTION].findIndex = zero;
    events[SDL_JOYBALLMOTION].findIndex = zero;
    events[SDL_JOYHATMOTION].findIndex = [&]() { return event.jhat.value; };
    events[SDL_JOYBUTTONDOWN].findIndex = [&]() { return event.jbutton.button; };
    events[SDL_JOYBUTTONUP].findIndex = [&]() { return event.jbutton.button; };
    events[SDL_JOYDEVICEADDED].findIndex = zero;
    events[SDL_JOYDEVICEREMOVED].findIndex = zero;
    events[SDL_CONTROLLERAXISMOTION].findIndex = [&]() { return event.caxis.axis; };
    events[SDL_CONTROLLERBUTTONDOWN].findIndex = [&]() { return event.cbutton.button; };
    events[SDL_CONTROLLERBUTTONUP].findIndex = [&]() { return event.cbutton.button; };
    events[SDL_CONTROLLERDEVICEADDED].findIndex = zero;
    events[SDL_CONTROLLERDEVICEREMOVED].findIndex = zero;
    events[SDL_CONTROLLERDEVICEREMAPPED].findIndex = zero;
    events[SDL_FINGERDOWN].findIndex = zero;
    events[SDL_FINGERUP].findIndex = zero;
    events[SDL_FINGERMOTION].findIndex = zero;
    events[SDL_DOLLARGESTURE].findIndex = [&]() { return event.dgesture.gestureId; };
    events[SDL_DOLLARRECORD].findIndex = [&]() { return event.dgesture.gestureId; };
    events[SDL_MULTIGESTURE].findIndex = zero;
    events[SDL_CLIPBOARDUPDATE].findIndex = zero;
    events[SDL_DROPFILE].findIndex = zero;
    events[SDL_DROPTEXT].findIndex = zero;
    events[SDL_DROPBEGIN].findIndex = zero;
    events[SDL_DROPCOMPLETE].findIndex = zero;
    events[SDL_AUDIODEVICEADDED].findIndex = zero;
    events[SDL_AUDIODEVICEREMOVED].findIndex = zero;
    events[SDL_RENDER_TARGETS_RESET].findIndex = zero;
    events[SDL_RENDER_DEVICE_RESET].findIndex = zero;
    events[SDL_USEREVENT].findIndex = [&]() { return event.user.code; };
}

void Input::update() {
    while (SDL_PollEvent(&event)) {
        notify();
    }
    execute();
}

void Input::notify() {
    observers = events[event.type - 1].subEvents.equal_range(events[event.type - 1].findIndex());
    for (auto iter = observers.first; iter != observers.second; iter++) {
        asyncCalls.push_back(std::async(std::launch::async, &Observer::pushEvent, iter->second, EventAlert({event, {event.type, events[event.type - 1].findIndex()}})));
    }
}

void Input::append(Observer* observer, unsigned int type, unsigned int subType) {
    events[type].subEvents.emplace(subType, observer);
}

void Input::release(Observer* observer, unsigned int type, unsigned int subType) {
    auto extremes = events[type - 1].subEvents.equal_range(subType);
    std::multimap<unsigned int, Observer*>::iterator iter;
    for (iter = extremes.first; iter != extremes.second && iter->second != observer; iter++) {}
    events[type - 1].subEvents.erase(iter);
}

void Input::execute() {
    for (auto& asyncCall: asyncCalls) {
        asyncCall.get();
    }
    asyncCalls.clear();
    for (auto iter = observers.first; iter != observers.second; iter++) {
        iter->second->update();
    }
}
