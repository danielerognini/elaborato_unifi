#include "Observer.h"

#include <utility>
#include <unordered_map>
#include "Input.h"

void Observer::append(const Signature& signature) {
    Input::getInstance().append(this, signature.event, signature.subEvent);
}

void Observer::release(const Signature& signature) {
    Input::getInstance().release(this, signature.event, signature.subEvent);
}

Observer::~Observer() {
    for (auto& signature: signatures) {
        release(signature.second);
    }
}

Observer::Observer(const std::map<std::string, Signature>& signatures, std::function<void()> function) : function(std::move(function)) {
    for (auto& signature: signatures) {
        if (this->signatures.emplace(signature.first, signature.second).second) {
            append(signature.second);
        }
    }
}

void Observer::pushEvent(EventAlert eventAlert) {
    buffer.push_back(eventAlert);
}

const Signature& Observer::getSignature(const std::string& name) const {
    auto result = signatures.find(name);
    if (result == signatures.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map");
    }
    return result->second;
}

bool Observer::changeSignature(const std::string& name, Signature signature) {
    auto iter = signatures.find(name);
    bool result = iter != signatures.end();
    if (result) {
        iter->second = signature;
    }
    return false;
}

void Observer::update() {
    function();
    buffer.clear();
}

bool Observer::hasTarget() const {
    return true;
}
