//
// Created by dom on 05/09/21.
//

#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <string>
#include <Activatable.h>
#include <map>
#include <memory>
#include <ECS/Manager.h>

class Menu : public Activatable {
public:
    Menu(std::string name, unsigned int priorityOffset, bool active);
    ~Menu() override;
    void enable() override;
    void disable() override;

private:
    std::string name;
    std::map<std::string, std::shared_ptr<Manager>> layers;
};

#endif //GAME_MENU_H
