#include "Animation.hpp"

Animation::Animation(float animationSpeed)
    : animationSpeed(animationSpeed), currentFrame(0), timeSinceLastFrame(0) {}

Animation::~Animation() {
    for (auto& frame : frames) {
        SDL_DestroyTexture(frame);
    }
}

void Animation::addFrame(SDL_Texture* texture) {
    frames.push_back(texture);
}

SDL_Texture* Animation::getCurrentFrame() const {
    return frames[currentFrame];
}

void Animation::update() {
    timeSinceLastFrame += animationSpeed;
    if (timeSinceLastFrame >= 1.0f) {
        timeSinceLastFrame = 0;
        currentFrame = (currentFrame + 1) % frames.size();
    }
}

bool Animation::isFinished() const {
    // Animation is finished if currentFrame is at the last frame
    return (currentFrame == frames.size() - 1);
}
