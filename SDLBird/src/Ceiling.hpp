//
//  Ceiling.hpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/30/24.
//

#ifndef Ceiling_hpp
#define Ceiling_hpp

#include <stdio.h>
#include <iostream>
#include <SDL3/SDL.h>
#include "Entity.hpp"
#include "Collisions.hpp"

class Ceiling: public Entity {;

public:
    std::string obj_name = "ceiling";

    Ceiling();
    
    /// Adds a positive velocity vector
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;
    void input(Uint32 eventType) override {};
};

#endif