//
// Created by dom on 01/09/21.
//

#include "SystemObserver.h"

#include <utility>

SystemObserver::SystemObserver(std::unordered_map<std::string, Signature> signatures, std::function<void()> function) : Observer(std::move(signatures)), function(std::move(function)) {
}

void SystemObserver::update() {
    function();
}
