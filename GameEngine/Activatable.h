#ifndef GAME_ACTIVATABLE_H
#define GAME_ACTIVATABLE_H


class Activatable {
public:
    const bool& isActive() const;
    void toggle();
    void toggle(const bool& status);
    virtual ~Activatable() = 0;
protected:
    bool active;
};


#endif //GAME_ACTIVATABLE_H
