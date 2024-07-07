//
//  Scene.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/27/24.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <list>
#include <stdbool.h>
#include "Entity.hpp"
#include <SDL3/SDL.h>

class Scene {
    /// List of entities registered to a scene in the order they appear.
    std::list<Entity*> entities;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool hasRanSetup;
    
    /// Generic function that loops through each entity in the list of entities and applies a function to it where entity is the parameter
    template<typename Func>
    void forEachEntity(Func func) {
        for (Entity* entity : entities) {
            func(entity);
        }
    }
public:
    /// Creates a new scene from the window and renderer
    Scene(SDL_Window *window, SDL_Renderer *renderer);
    /// The order entities are added will dictate the order in which they appear from top to bottom
    void addEntity(Entity *entity);
    
    /// runs the setup of each entity in the order it was added to the scene
    void setup();
    
    /// Forwards events onto the entities registered for a screen
    void input(Uint32 eventType);
    
    /// updates each entity in the order it was added to the scene
    void update();
    
    /// renders of each entity in the order it was added to the scene
    void render();
    
    /// Removes an entity from the scene
    void removeEntity(Entity *entity);
};

#endif /* Scene_hpp */
