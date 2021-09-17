#include <list>
#include <Engine.h>
#include "Menu.h"

Menu::Menu(std::string name, unsigned int priorityOffset, bool active) : Activatable(active), name(name) {
    std::list<std::string> layersNames = {name + "_background", name + "_windows", name + "buttons"};
    for (int i = 0; i < layersNames.size(); i++) {
        Engine::getInstance().addManager(*std::next(layersNames.begin(), i), i + priorityOffset);
        layers.emplace(*std::next(layersNames.begin(), i), &Engine::getInstance().getManager(*std::next(layersNames.begin(), i)));
    }
}

void Menu::enable() {
    Activatable::enable();
    for (auto& layer: layers) {
        layer.second->enable();
    }
}

void Menu::disable() {
    Activatable::disable();
    for (auto& layer: layers) {
        layer.second->disable();
    }
}

Menu::~Menu() {
    for (auto& layer: layers) {
        Engine::getInstance().removeManager(layer.first);
    }
}
