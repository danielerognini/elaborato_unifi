#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include <map>
#include <string>

class Room : public Activatable {
public:
    Room(const std::string& name, const std::string& roomTemplate, unsigned int priorityOffset, bool discovered, bool active);
    ~Room() override;
    
    void enable() override;
    void disable() override;
    
    std::map<std::string, std::shared_ptr<Manager>>::iterator begin();
    std::map<std::string, std::shared_ptr<Manager>>::iterator end();
    
    bool isDiscovered() const;
    void discover();
    
    void setPosition(const Vector2D& position);
    const Vector2D& getPosition();
    const Vector2D& getDimension();
    
    void lock();
    void unlock();

private:
    bool discovered;
    std::string name;
    std::map<std::string, std::shared_ptr<Manager>> layers;
    Vector2D position;
    Vector2D dimension;
};


#endif //GAME_ROOM_H
