//
//  Bird.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/12/24.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "PhysicsBody.hpp"
#include "ImageLoader.hpp"
#include "vector"
#include "AnimationController.hpp"
#include "Collisions.hpp"

class Bird: public Entity {;
    PhysicsBody physicsBody;
    AnimationController animationController;

    float flapStrength;
    
public:
    std::string obj_name = "bird";
    Bird();
    int score = 0;
    /// Adds a positive velocity vector
    void addUpwardVelocity();
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void input(Uint32 eventType) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;

    void setupAnimations(SDL_Renderer *renderer);
};

#endif /* Bird_hpp */
