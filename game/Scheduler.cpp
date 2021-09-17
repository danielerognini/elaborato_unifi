#include "Scheduler.h"
#include <fstream>

Scheduler::Scheduler() {
    //event mapping file parsing -----------------
    std::ifstream file("../config/events_mapping.txt"); //TODO: confirm file location
    std::string name;
    std::string event;
    std::string subEvent;
    while (getline(file, name, ' ')) {
        if (getline(file, event, ' ') && getline(file, subEvent)) {
            events.emplace(name, Signature{static_cast<unsigned int>(std::stoul(event)), static_cast<unsigned int>(std::stoul(subEvent))});
        }
    }
    file.close();
    //-------------------------------------------
}

void Scheduler::update() {
    for (auto iter = observers.begin(); iter != observers.end(); iter++) {
        if (!(*iter)->hasTarget()) {
            observers.erase(iter);
        }
    }
}

void Scheduler::addObserver(Observer* observer) {
    observers.emplace_back(u_ptr<Observer>(observer));
}

Scheduler& Scheduler::getInstance() {
    static Scheduler scheduler = Scheduler();
    return scheduler;
}

void Scheduler::remapEvent(const std::string& event, Signature signature) {
    std::string newFile;
    std::string line;
    std::ifstream iFile("../config/events_mapping.txt");
    while (getline(iFile, line)) {
        if (line.substr(0, line.find(' ')) == event) {
            line = event + " " + std::to_string(signature.event) + " " + std::to_string(signature.subEvent);
        }
        newFile += line + '\n';
    }
    iFile.close();
    std::ofstream oFile("../config/events_mapping.txt", std::ios::trunc);
    oFile << newFile;
    oFile.close();
    
    for (auto& observer: observers) {
        observer->changeSignature(event, signature);
    }
}
