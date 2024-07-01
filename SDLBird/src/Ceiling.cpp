//
//  Ceiling.cpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/30/24.
//

    
#include "Ceiling.hpp"

Ceiling::Ceiling() {}


void Ceiling::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    SDL_FRect ceilingCollisionBox = Collisions::getInstance().createCollisionBox(0.0f, -50.0f, static_cast<float>(windowWidth), 5.0f);
    Collisions::getInstance().addCollisionBox(obj_name, ceilingCollisionBox);
}
void Ceiling::update(){

}
void Ceiling::render(SDL_Renderer *renderer){

}