#ifndef GAME_ACTIVATABLE_H
#define GAME_ACTIVATABLE_H

class Activatable {
public:
    explicit Activatable(bool active = true);
    bool isActive() const;
    void toggle();
    void toggle(bool status);
    virtual ~Activatable() = 0;
protected:
    bool active;
};

#endif //GAME_ACTIVATABLE_H
