#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "SDL2/SDL.h"
#include "Animation.h"
#include "../../Activatable.h"
#include <string>
#include <unordered_map>

class Sprite : public Activatable{
private:
    std::string textureName;

    //variables used to manage animations
    bool animated = false; //defines if a sprite is animated or not. By default the sprite is not animated
    int frames = 0; //the number of frames of the animation
    int speed = 100; //defines the speed of the animation. The value corresponds to the delay between each frame in milliseconds
    int animationIndex;

    SDL_Rect* srcRect;

    std::string currentAnimation;
    std::unordered_map<std::string, Animation> animations;

    SDL_RendererFlip flip;
public:
    explicit Sprite(std::string textureName, bool active = true);

    void update();

    SDL_Rect& getSrcRect();
    void setSrcRect(SDL_Rect rect);

    bool addAnimation(std::string name, int index, int frames, int speed);
    bool removeAnimation(std::string name);

    std::string getTextureName();

    void setCurrentAnimation(std::string animationName);
    std::string getCurrentAnimation();

    SDL_RendererFlip& getFlip();
};

#endif //GAME_SPRITE_H