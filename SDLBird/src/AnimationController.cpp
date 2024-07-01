#include "AnimationController.hpp"

AnimationController::AnimationController() : currentAnimation(nullptr) {}

AnimationController::~AnimationController() {
    for (auto& pair : animations) {
        delete pair.second;
    }
}

void AnimationController::addAnimation(const std::string& name, Animation* animation) {
    animations[name] = animation;
}

void AnimationController::setAnimation(const std::string& name) {
    auto it = animations.find(name);
    if (it != animations.end()) {
        currentAnimation = it->second;
        currentAnimationName = name;
    }
}

void AnimationController::update() {
    if (currentAnimation) {
        currentAnimation->update();
    }
}

void AnimationController::render(SDL_Renderer* renderer, const SDL_FRect& destination) {
    if (currentAnimation) {
        SDL_Texture* frameTexture = currentAnimation->getCurrentFrame();
        if (frameTexture) {
            SDL_RenderTexture(renderer, frameTexture, NULL, &destination);
        }
    }
}

bool AnimationController::isAnimationFinished() const {
    if (currentAnimation) {
        return currentAnimation->isFinished();
    }
    return true; // Return true if no animation is set or if currentAnimation is nullptr
}

std::string AnimationController::getAnimationName() const {
    return currentAnimationName; // Return the stored current animation name
}