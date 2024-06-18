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

class Bird {
    SDL_FRect frame;
    SDL_Texture *texture;
    
public:
    Bird();
    
    /// Adds a positive velocity vector
    void addUpwardVelocity();
    void setup(SDL_Window *window, SDL_Renderer *renderer);
    void update();
    void render(SDL_Renderer *renderer);
};

#endif /* Bird_hpp */
