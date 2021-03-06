#include <Engine.h>
#include "Animation.h"

Animation::Animation(int index, int frames, int speed, bool frozen) : index(index), frames(frames), speed(speed), frozen(frozen), currentFrame(0) {}

void Animation::updateRect(SDL_Rect& srcRect) {
    srcRect.x = srcRect.w * (currentFrame % speed);
    srcRect.y = index * srcRect.h;
    if (frames * speed >= currentFrame) {
        currentFrame = 0;
    } else {
        currentFrame++;
    }
}

void Animation::restartAnimation() {
    this->currentFrame = 0;
}

unsigned short int Animation::getFrames() const {
    return frames;
}
