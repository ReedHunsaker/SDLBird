//
//  PhysicsBody.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/18/24.
//

#ifndef PhysicsBody_hpp
#define PhysicsBody_hpp

#include <stdio.h>
#include <SDL3/SDL.h>
#include "Entity.hpp"
#include "stdbool.h"
#include "Constants.hpp"

struct Vector {
    float x;
    float y;
};

/// A type of entity that has physics applied including gravity
class PhysicsBody {
    Vector velocity;
    bool isEnabled;
    float gravityAcceleration; // 500 points per second
    
public:
    PhysicsBody();
    void update(SDL_FRect *frame);
    void setVelocity(Vector newVelocity);
    
    void setEnablePhysics(bool isEnabled);
};


#endif /* PhysicsBody_hpp */
