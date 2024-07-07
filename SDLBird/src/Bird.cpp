//
//  Bird.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/12/24.
//

#include "Bird.hpp"

Bird::Bird() {
    physicsBody = PhysicsBody();
}
    
void Bird::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int windowWidth = 0;
    int windowHeight = 0;
    int *x = &windowWidth, *y = &windowHeight;
    int width = 34, height = 24;

    setupAnimations(renderer);
    animationController.setAnimation("idle");

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
    //collisions
    Collisions::getInstance().addCollisionBox(obj_name, frame);

}

void Bird::input(Uint32 eventType) {
    switch (eventType) {
        case SDL_EVENT_KEY_DOWN: case SDL_EVENT_FINGER_DOWN:
            addUpwardVelocity();
            animationController.setAnimation("flying");
            break;
    }
}

void Bird::update() {
    physicsBody.update(&frame);
    //collisions
    Collisions::getInstance().updateCollisionBoxPosition(obj_name, frame.x, frame.y);
    Collisions::getInstance().checkObjectCollision(obj_name);
    
    Uint64 elapsedTime = SDL_GetTicks() - animationTimer;
    if (elapsedTime > animationTickTime) {
        (this->*animation)();
        animationTimer = SDL_GetTicks();
    }
    animationController.update();
}

void Bird::render(SDL_Renderer *renderer) {
    if (SDL_RenderTexture(renderer, textures[textureIndex], NULL, &frame) != 0) {
        SDL_Log("Error drawing texture: %s", SDL_GetError());
        return;
    }
    ////Renders all hit boxes, used for debugging bird hitbox.
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    //     for (const auto& box : Collisions::getInstance().collisionBoxes) {
    //         if (SDL_RenderFillRect(renderer, box.second) != 0) {
    //             SDL_Log("Error drawing collisionBox: %s", SDL_GetError());
    //         }
    //     }
    animationController.render(renderer, frame);
}

void Bird::addUpwardVelocity() {
    physicsBody.setEnablePhysics(true);
    Vector velocityVector = Vector();
    velocityVector.x = 0;
    velocityVector.y = flapStrength;
    
    physicsBody.setVelocity(velocityVector);
}

void Bird::setupAnimations(SDL_Renderer *renderer) {
    Animation* idleAnimation = new Animation(0.0f);
    SDL_Texture* birdMidFlap = loadImage(renderer, "bird-midFlap.png");
    idleAnimation->addFrame(birdMidFlap);

    Animation* flyingAnimation = new Animation(0.085f);
    SDL_Texture* birdDownFlap = loadImage(renderer, "bird-downFlap.png");
    SDL_Texture* birdUpFlap = loadImage(renderer, "bird-upFlap.png");

    flyingAnimation->addFrame(birdDownFlap);
    flyingAnimation->addFrame(birdMidFlap);
    flyingAnimation->addFrame(birdUpFlap);
    flyingAnimation->addFrame(birdMidFlap);

    animationController.addAnimation("idle", idleAnimation);
    animationController.addAnimation("flying", flyingAnimation);
}