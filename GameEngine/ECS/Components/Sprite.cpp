#include "Sprite.h"

Sprite::Sprite(std::string textureName, bool active) : textureName(textureName){
    this->active = active;
}

void Sprite::update() {
    animations.find(currentAnimation)->second.updateRect(*srcRect);
}

SDL_Rect& Sprite::getSrcRect() {
    return *srcRect;
}

void Sprite::setSrcRect(SDL_Rect rect) {
    srcRect = &rect;
}

bool Sprite::addAnimation(std::string name, int index, int frames, int speed) {
    return animations.emplace(name, Animation(index, frames, speed)).second;
}

bool Sprite::removeAnimation(std::string name) {
    return animations.erase(name);
}

std::string Sprite::getTextureName() {
    return textureName;
}

void Sprite::setCurrentAnimation(std::string animationName) {
    currentAnimation = animationName;
}

std::string Sprite::getCurrentAnimation() {
    return currentAnimation;
}

SDL_RendererFlip& Sprite::getFlip() {
    return flip;
}

void Sprite::setTextureName(std::string textureName) {
    this->textureName = textureName;
}

Sprite::Sprite(bool active) {
    this->active = active;
}
