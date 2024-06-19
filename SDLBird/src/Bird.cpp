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
    
    texture = loadImage(renderer, "bird.png");
    
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
}

void Bird::render(SDL_Renderer *renderer) {
    if (SDL_RenderTexture(renderer, texture, NULL, &frame) != 0) {
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
