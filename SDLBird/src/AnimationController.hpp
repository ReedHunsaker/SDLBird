#ifndef ANIMATIONCONTROLLER_HPP
#define ANIMATIONCONTROLLER_HPP

#include <string>
#include <map>
#include "Animation.hpp"

class AnimationController {
public:
    AnimationController();
    ~AnimationController();

    void addAnimation(const std::string& name, Animation* animation);
    void setAnimation(const std::string& name);
    bool isAnimationFinished() const;
    std::string getAnimationName() const;

    void update();
    void render(SDL_Renderer* renderer, const SDL_FRect& destination);

private:
    std::map<std::string, Animation*> animations;
    Animation* currentAnimation;
    std::string currentAnimationName; // Store current animation name
};

#endif // ANIMATIONCONTROLLER_HPP
