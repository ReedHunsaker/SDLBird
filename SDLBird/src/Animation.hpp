#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <SDL3/SDL.h>

class Animation {
public:
    Animation(float animationSpeed);
    ~Animation();

    void addFrame(SDL_Texture* texture);
    SDL_Texture* getCurrentFrame() const;
    bool isFinished() const;
    
    void update();

private:
    std::vector<SDL_Texture*> frames;
    int currentFrame;
    float animationSpeed;
    float timeSinceLastFrame;
};

#endif // ANIMATION_HPP
