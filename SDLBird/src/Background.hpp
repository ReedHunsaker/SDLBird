//
//  Bird.hpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/18/24.
//

#ifndef Background_hpp
#define Background_hpp

#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Background {
    SDL_FRect frame1;
    SDL_FRect frame2;
    SDL_Texture *texture;
    int background_speed = 2.5;
    
public:
    Background();
    
    /// Adds a positive velocity vector
    void setup(SDL_Window *window, SDL_Renderer *renderer);
    void update();
    void render(SDL_Renderer *renderer);
};

#endif /* Background_hpp */
