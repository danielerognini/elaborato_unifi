#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include "SDL2/SDL.h"
#include "../../Vector2D.h"

class Animation {
public:
    Animation(int index, int frames, int speed);
    void updateRect(SDL_Rect& srcRect);
    void restartAnimation();
    unsigned short int getFrames();

private:
    unsigned short int index;
    unsigned short int frames;
    unsigned short int speed;
    unsigned short int currentFrame;
};

#endif //GAME_ANIMATION_H
