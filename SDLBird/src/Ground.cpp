//
//  Ground.cpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/30/24.
//

    
#include "Ground.hpp"

Ground::Ground() {}


void Ground::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    SDL_FRect groundCollisionBox = Collisions::getInstance().createCollisionBox(0.0f, static_cast<float>(windowHeight + 5), static_cast<float>(windowWidth), 5.0f);
    Collisions::getInstance().addCollisionBox(obj_name, groundCollisionBox);

}
void Ground::update(){

}
void Ground::render(SDL_Renderer *renderer){

}