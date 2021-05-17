#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include "SDL2/SDL.h"
#include "../../Vector2D.h"

class Animation {
public:
    Animation(const int& index, const int& frames, const int& speed);
    void updateRect(SDL_Rect& srcRect);

private:
    int index;
    int frames;
    int speed;
};

#endif //GAME_ANIMATION_H
