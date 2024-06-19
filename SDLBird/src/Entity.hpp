//
//  Entity.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/18/24.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <list>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

/// An object that can be rendered by the device
class Entity {
    
protected:
    Entity();
    
public:
    SDL_FRect frame;
    virtual void setup(SDL_Window *window, SDL_Renderer *renderer) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
};

extern std::list<Entity*> entities;

#endif /* Entity_hpp */
