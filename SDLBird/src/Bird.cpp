//
//  Bird.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/12/24.
//

#include "Bird.hpp"

Bird::Bird() {}
    
void Bird::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int windowWidth = 0;
    int windowHeight = 0;
    int *x = &windowWidth, *y = &windowHeight;
    int width = 34, height = 24;
    
    textures.push_back(loadImage(renderer, "bird-downFlap.png"));
    textures.push_back(loadImage(renderer, "bird-midFlap.png"));
    textures.push_back(loadImage(renderer, "bird-upFlap.png"));
    
    textureIndex = 0;
    animationFPS = 6;
    animationTimer = SDL_GetTicks();
    animationTickTime = 1000 / animationFPS;
    animation = &Bird::incrementAnimation;
    
    frame = SDL_FRect();
    
    if (SDL_GetWindowSize(window, x, y) != 0) {
        SDL_Log("Error getting window size: %s", SDL_GetError());
        *x = 0;
        *y = 0;
    }
    
    frame.h = height;
    frame.w = width;
    
    float midHeight = height / 2;
    float midWidth = width / 2;
    
    // set in the middle of the screen
    frame.x = (*x * 0.5) - midHeight;
    frame.y = (*y * 0.5) - midWidth;
    
    flapStrength = -300;

}

void Bird::update() {
    PhysicsBody::update();

    
    Uint64 elapsedTime = SDL_GetTicks() - animationTimer;
    if (elapsedTime > animationTickTime) {
        (this->*animation)();
        animationTimer = SDL_GetTicks();
    }
}

void Bird::render(SDL_Renderer *renderer) {
    if (SDL_RenderTexture(renderer, textures[textureIndex], NULL, &frame) != 0) {
        SDL_Log("Error drawing texture: %s", SDL_GetError());
        return;
    }
}

void Bird::addUpwardVelocity() {
    PhysicsBody::setEnablePhysics(true);
    Vector velocityVector = Vector();
    velocityVector.x = 0;
    velocityVector.y = flapStrength;
    
    PhysicsBody::setVelocity(velocityVector);
}

void Bird::incrementAnimation() {
    // gross but it works 🤷
    textureIndex += 1;
    if (textureIndex > 2) {
        textureIndex = 1;
        animation = &Bird::decrementAnimation;
    }
}

void Bird::decrementAnimation() {
    // gross but it works 🤷
    textureIndex -= 1;
    if (textureIndex < 0) {
        textureIndex = 1;
        animation = &Bird::incrementAnimation;
    }
}