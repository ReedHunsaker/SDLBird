//
//  Pipes.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/26/24.
//

#ifndef Pipes_hpp
#define Pipes_hpp

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include <random>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "ImageLoader.hpp"
#include "Entity.hpp"
#include "Constants.hpp"
#include "Collisions.hpp"
#include <iostream>
#include "UUID.hpp"
#include "Bird.hpp"
#include "Text.hpp"

class Pipes: public Entity {
    std::string obj_name = "pipes";
    std::string id;
    /// Gap between top and bottom pipe
    float pipeGap;
    
    /// Speed at which pipe moves in the x direction
    float pipeSpeed;
    
    /// Boolean that states if the game has started
    bool didStart;
    
    /// Random offset to place the pipe gap
    float randomOffset;
    
    /// Offset between pipes
    float spawnOffset;
    
    float midX;
    
    bool didPass = false;
    
    // MARK: Textures and rets
    SDL_Texture *topPipeTexture;
    SDL_Texture *bottomPipeTexture;
    SDL_FRect topPipeFrame;
    SDL_FRect bottomPipeFrame;
    
    // MARK: Window references
    int windowHeight;
    int windowWidth;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    /// Reset the pipes to the trailing side of the screen
    void resetPipes(float spawnOffset);
    void checkBirdPass();
    
    
public:
    float pipeWidth;
    
    Bird *player;
    Text *score;
    Pipes();
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void update() override;
    void input(Uint32 eventType) override;
    void render(SDL_Renderer *renderer) override;
    
    /// Set spawn offset of pipe to trailing side of screen
    void setSpawnOffset(float offset);
    
    /// Start moving the pipes
    void start();
    
    /// Stop the pipes from moving
    void stop();
};

#endif /* Pipe_hpp */
