#include "Animation.h"

Animation::Animation(const int& index, const int& frames, const int& speed) : index(index), frames(frames), speed(speed) {}

void Animation::updateRect(SDL_Rect& srcRect) {
    srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
    srcRect.y = index * srcRect.h;
}
