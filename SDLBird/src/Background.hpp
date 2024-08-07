//
//  Bird.hpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/18/24.
//

#ifndef Background_hpp
#define Background_hpp

#include <iostream>
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "ImageLoader.hpp"
#include "Entity.hpp"

class Background: public Entity {

    SDL_FRect frame1;
    SDL_FRect frame2;
    SDL_Texture *texture;
    int background_speed = 2.5;
    
    SDL_Texture *getBackgroundTexture(SDL_Renderer *renderer);
    
public:
    std::string obj_name = "background";
    Background();
    
    /// Adds a positive velocity vector
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void update() override;
    void input(Uint32 eventType) override {};
    void render(SDL_Renderer *renderer) override;
};

#endif /* Background_hpp */
