#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include "SDL2/SDL.h"
#include "../../Vector2D.h"

class Animation {
private:
    int index;
    int frames;
    int speed;

public:
    Animation(int index, int frames, int speed);
    void updateRect(SDL_Rect& srcRect);
};

#endif //GAME_ANIMATION_H
