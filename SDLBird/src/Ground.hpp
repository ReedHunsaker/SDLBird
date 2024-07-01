//
//  Ground.hpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/30/24.
//

#ifndef Ground_hpp
#define Ground_hpp

#include <stdio.h>
#include <iostream>
#include <SDL3/SDL.h>
#include "Entity.hpp"
#include "Collisions.hpp"


class Ground: public Entity {;

public:
    std::string obj_name = "ground";
    Ground();
    
    /// Adds a positive velocity vector
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;
    void input(Uint32 eventType) override {};
};

#endif