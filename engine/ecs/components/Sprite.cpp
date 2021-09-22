#include "Sprite.h"

Sprite::Sprite(const std::string& texturePath, const std::string& currentAnimation, bool active) : Activatable(active), texturePath(texturePath), currentAnimation(currentAnimation), animationFrames(0), temporary(false), flip(SDL_FLIP_NONE) {
}

void Sprite::update() {
    animations.find(currentAnimation)->second.updateRect(srcRect);
    if (temporary && --animationFrames == 0) {
        currentAnimation = nextAnimation;
        nextAnimation = "";
        temporary = false;
    }
}

const SDL_Rect& Sprite::getSrcRect() {
    return srcRect;
}

void Sprite::setSrcRect(const SDL_Rect& rect) {
    srcRect = rect;
}

bool Sprite::addAnimation(const std::string& name, int index, int frames, int speed) {
    return animations.emplace(name, Animation(index, frames, speed, false)).second;
}

bool Sprite::removeAnimation(const std::string& name) {
    return animations.erase(name);
}

const std::string& Sprite::getTexturePath() {
    return texturePath;
}

void Sprite::setCurrentAnimation(const std::string& name) {
    currentAnimation = name;
}

const std::string& Sprite::getCurrentAnimation() {
    return currentAnimation;
}

const SDL_RendererFlip& Sprite::getFlip() {
    return flip;
}

void Sprite::setTexturePath(const std::string& texturePath) {
    this->texturePath = texturePath;
}

void Sprite::setFlip(const SDL_RendererFlip& flip) {
    this->flip = flip;
}

void Sprite::playAnimation(const std::string& animation, const std::string& nextAnimation) {
    this->nextAnimation = nextAnimation;
    if (this->nextAnimation.empty()) {
        this->nextAnimation = currentAnimation;
    }
    currentAnimation = animation;
    animationFrames = animations.find(currentAnimation)->second.getFrames();
    temporary = true;
    animations.find(currentAnimation)->second.restartAnimation();
}
