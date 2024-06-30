//
//  PhysicsBody.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/18/24.
//

#include "PhysicsBody.hpp"

PhysicsBody::PhysicsBody() {
    velocity = Vector();
    velocity.x = 0;
    velocity.y = 0;
    
    isEnabled = false;
    gravityAcceleration = 500.0;
}

void PhysicsBody::update(SDL_FRect *frame) {
    if (!isEnabled) { return; }
    
    // apply the velocity to the position
    velocity.y += gravityAcceleration * Constants::tickTimeSeconds;
    frame->y += velocity.y * Constants::tickTimeSeconds;
    frame->x += velocity.x;
}

void PhysicsBody::setVelocity(Vector newVelocity) {
    if (!isEnabled) { return; }
    velocity.y = newVelocity.y;
    velocity.x = newVelocity.x;
}

void PhysicsBody::setEnablePhysics(bool isEnabled) {
    this->isEnabled = isEnabled;
}
