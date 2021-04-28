#ifndef GAME_ACTIVATABLE_H
#define GAME_ACTIVATABLE_H


class Activatable {
protected:
    bool active;
public:
    bool isActive() const;
    void toggle();
    void toggle(const bool status);
};


#endif //GAME_ACTIVATABLE_H
