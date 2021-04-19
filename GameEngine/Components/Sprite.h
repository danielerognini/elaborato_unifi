#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "SDL.h"
#include <string>

class Sprite {
private:
    std::string textureName;

    //variables used to manage animations
    bool animated = false; //defines if a sprite is animated or not. By default the sprite is not animated
    int frames = 0; //the number of frames of the animation
    int speed = 100; //defines the speed of the animation. The value corresponds to the delay between each frame in milliseconds
    int animationIndex;

    SDL_Rect srcRect;

public:
    void update();
    void draw();

    SDL_Rect getSrcRect();
    void setSrcRect(SDL_Rect rect);
};

#endif //GAME_SPRITE_H
