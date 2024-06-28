//
//  Pipes.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/26/24.
//

#ifndef Pipes_hpp
#define Pipes_hpp

#include <stdio.h>
#include "stdbool.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "ImageLoader.hpp"
#include "Entity.hpp"

class Pipes: public Entity {
    SDL_Texture *topPipeTexture;
    SDL_Texture *bottomPipeTexture;
    SDL_FRect topPipeFrame;
    SDL_FRect bottomPipeFrame;
    float pipeGap;
    float pipeSpeed;
    bool didStart;
    
public:
    Pipes();
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;
    void start();
};

#endif /* Pipe_hpp */
