#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "SDL2/SDL.h"
#include "Animation.h"
#include "../../Activatable.h"
#include <string>
#include <unordered_map>

class Sprite : public Activatable {
public:
    explicit Sprite(const std::string& texturePath, bool active);
    
    void update();
    
    const SDL_Rect& getSrcRect();
    void setSrcRect(const SDL_Rect& rect);
    
    bool addAnimation(const std::string& name, int index, int frames, int speed);
    bool removeAnimation(const std::string& name);
    
    const std::string& getTexturePath();
    void setTexturePath(const std::string& texturePath);
    
    const std::string& getCurrentAnimation();
    void setCurrentAnimation(const std::string& name);
    
    void playAnimation(const std::string& animation, const std::string& nextAnimation = "");
    
    const SDL_RendererFlip& getFlip();
    void setFlip(const SDL_RendererFlip& flip);

private:
    std::string texturePath;
    SDL_Rect srcRect;
    
    std::string currentAnimation;
    std::string nextAnimation;
    unsigned short int animationFrames;
    bool temporary;
    std::unordered_map<std::string, Animation> animations;
    
    SDL_RendererFlip flip;
};

#endif //GAME_SPRITE_H
