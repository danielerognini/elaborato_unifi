#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include <map>
#include <string>

class Room : public Activatable {
public:
    Room(const std::string& name, const std::string& roomTemplate, unsigned int priorityOffset, bool discovered, bool active);
    ~Room();
    void enable() override;
    void disable() override;
    std::map<std::string, std::shared_ptr<Manager>>::iterator begin();
    std::map<std::string, std::shared_ptr<Manager>>::iterator end();
    bool isDiscovered() const;
    void discover();
    void lock();
    void unlock();

private:
    bool discovered;
    std::string name;
    std::map<std::string, std::shared_ptr<Manager>> layers;
};


#endif //GAME_ROOM_H
