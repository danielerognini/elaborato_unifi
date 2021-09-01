#include "Observer.h"

#include <utility>
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

Observer::Observer(std::unordered_map<std::string, Signature> signatures) {
    for (auto& signature: signatures) {
        addSignature(signature.first, signature.second);
    }
}

void Observer::pushEvent(EventAlert eventAlert) {
    buffer.push_back(eventAlert);
}

bool Observer::addSignature(std::string name, Signature signature) {
    bool result = signatures.emplace(name, signature).second;
    if (result) {
        append(signature);
    }
    return result;
}

bool Observer::removeSignature(std::string name) {
    auto iter = signatures.find(name);
    bool result = iter != signatures.end();
    if (result) {
        Signature signature = iter->second;
        signatures.erase(name);
        release(signature);
    }
    return result;
}

const Signature& Observer::getSignature(std::string name) const {
    auto result = signatures.find(name);
    if (result == signatures.end()) {
        throw std::runtime_error("\"" + name + "\" key does not exists in this unordered_map");
    }
    return result->second;
}

bool Observer::modifySignature(std::string name, Signature signature) {
    auto iter = signatures.find(name);
    bool result = iter != signatures.end();
    if (result) {
        iter->second = signature;
    }
    return false;
}
