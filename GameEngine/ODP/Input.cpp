#include <future>
#include "Input.h"
#include "Engine.h"

Input& Input::getInstance() {
    static Input instance;
    return instance;
}

Input::Input() : event(SDL_Event()) {
    std::function<unsigned int()> zero = [&]() { return 0; };
    events[SDL_QUIT - 1].findIndex = zero;
    events[SDL_APP_TERMINATING - 1].findIndex = zero;
    events[SDL_APP_LOWMEMORY - 1].findIndex = zero;
    events[SDL_APP_WILLENTERBACKGROUND - 1].findIndex = zero;
    events[SDL_APP_DIDENTERBACKGROUND - 1].findIndex = zero;
    events[SDL_APP_WILLENTERFOREGROUND - 1].findIndex = zero;
    events[SDL_APP_DIDENTERFOREGROUND - 1].findIndex = zero;
    events[SDL_WINDOWEVENT - 1].findIndex = [&]() { return event.window.event; };
    events[SDL_SYSWMEVENT - 1].findIndex = zero;
    events[SDL_KEYDOWN - 1].findIndex = [&]() { return event.key.keysym.sym; };
    events[SDL_KEYUP - 1].findIndex = [&]() { return event.key.keysym.sym; };
    events[SDL_TEXTEDITING - 1].findIndex = zero;
    events[SDL_TEXTINPUT - 1].findIndex = zero;
    events[SDL_KEYMAPCHANGED - 1].findIndex = zero;
    events[SDL_MOUSEMOTION - 1].findIndex = zero;
    events[SDL_MOUSEBUTTONDOWN - 1].findIndex = [&]() { return event.button.button; };
    events[SDL_MOUSEBUTTONUP - 1].findIndex = [&]() { return event.button.button; };
    events[SDL_MOUSEWHEEL - 1].findIndex = zero;
    events[SDL_JOYAXISMOTION - 1].findIndex = zero;
    events[SDL_JOYBALLMOTION - 1].findIndex = zero;
    events[SDL_JOYHATMOTION - 1].findIndex = [&]() { return event.jhat.value; };
    events[SDL_JOYBUTTONDOWN - 1].findIndex = [&]() { return event.jbutton.button; };
    events[SDL_JOYBUTTONUP - 1].findIndex = [&]() { return event.jbutton.button; };
    events[SDL_JOYDEVICEADDED - 1].findIndex = zero;
    events[SDL_JOYDEVICEREMOVED - 1].findIndex = zero;
    events[SDL_CONTROLLERAXISMOTION - 1].findIndex = [&]() { return event.caxis.axis; };
    events[SDL_CONTROLLERBUTTONDOWN - 1].findIndex = [&]() { return event.cbutton.button; };
    events[SDL_CONTROLLERBUTTONUP - 1].findIndex = [&]() { return event.cbutton.button; };
    events[SDL_CONTROLLERDEVICEADDED - 1].findIndex = zero;
    events[SDL_CONTROLLERDEVICEREMOVED - 1].findIndex = zero;
    events[SDL_CONTROLLERDEVICEREMAPPED - 1].findIndex = zero;
    events[SDL_FINGERDOWN - 1].findIndex = zero;
    events[SDL_FINGERUP - 1].findIndex = zero;
    events[SDL_FINGERMOTION - 1].findIndex = zero;
    events[SDL_DOLLARGESTURE - 1].findIndex = [&]() { return event.dgesture.gestureId; };
    events[SDL_DOLLARRECORD - 1].findIndex = [&]() { return event.dgesture.gestureId; };
    events[SDL_MULTIGESTURE - 1].findIndex = zero;
    events[SDL_CLIPBOARDUPDATE - 1].findIndex = zero;
    events[SDL_DROPFILE - 1].findIndex = zero;
    events[SDL_DROPTEXT - 1].findIndex = zero;
    events[SDL_DROPBEGIN - 1].findIndex = zero;
    events[SDL_DROPCOMPLETE - 1].findIndex = zero;
    events[SDL_AUDIODEVICEADDED - 1].findIndex = zero;
    events[SDL_AUDIODEVICEREMOVED - 1].findIndex = zero;
    events[SDL_RENDER_TARGETS_RESET - 1].findIndex = zero;
    events[SDL_RENDER_DEVICE_RESET - 1].findIndex = zero;
    events[SDL_USEREVENT - 1].findIndex = [&]() { return event.user.code; };
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
