#include "Sprite.h"

void Sprite::update() {}

void Sprite::draw() {

}

SDL_Rect Sprite::getSrcRect() {
    return srcRect;
}

void Sprite::setSrcRect(SDL_Rect rect) {
    srcRect = rect;
}
