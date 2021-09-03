//
// Created by dom on 01/09/21.
//

#ifndef GAME_SYSTEMOBSERVER_H
#define GAME_SYSTEMOBSERVER_H

#include "Observer.h"

class SystemObserver : public Observer {
public:
    void update() override;
    
    SystemObserver(std::unordered_map<std::string, Signature> signatures, std::function<void()> function);
    ~SystemObserver() override = default;

private:
    std::function<void()> function;
};

#endif //GAME_SYSTEMOBSERVER_H
