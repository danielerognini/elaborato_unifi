#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

class Animation {
private:
    int index;
    int frames;
    int speed;

public:
    explicit Animation(int index = 0, int frames = 1, int speed = 0);
};

#endif //GAME_ANIMATION_H
