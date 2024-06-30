//
//  Bird.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/12/24.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "PhysicsBody.hpp"
#include "ImageLoader.hpp"
#include "vector"
#include "Collisions.hpp"

class Bird: public Entity {;
    std::vector<SDL_Texture*> textures;
    int textureIndex;
    float animationFPS;
    float animationTickTime;
    Uint64 animationTimer;
    PhysicsBody physicsBody;
    /// Rotation of sprite in degrees
    float rotation;
    float flapStrength;
    void (Bird::*animation)();

    Collisions collisions;
    
    void incrementAnimation();
    void decrementAnimation();

public:
    Bird();
    
    /// Adds a positive velocity vector
    void addUpwardVelocity();
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void input(Uint32 eventType) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;
};

#endif /* Bird_hpp */
