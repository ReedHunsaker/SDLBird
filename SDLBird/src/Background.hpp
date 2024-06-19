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
#include "ImageLoader.hpp"
#include "Entity.hpp"

class Background: Entity {
    SDL_FRect frame1;
    SDL_FRect frame2;
    SDL_Texture *texture;
    int background_speed = 2.5;
    
    SDL_Texture *getBackgroundTexture(SDL_Renderer *renderer);
    
public:
    Background();
    
    /// Adds a positive velocity vector
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;
};

#endif /* Background_hpp */
