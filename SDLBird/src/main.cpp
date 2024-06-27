//
//  main.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 5/31/24.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "Bird.hpp"
#include "Background.hpp"
#include "Collisions.hpp"

SDL_Window *window;
SDL_Renderer *renderer;
Background background = Background();
Bird bird = Bird();
Collisions collisions = Collisions();

Background *pBackground = &background;
Bird *pBird = &bird;
Collisions *pCollisions = &collisions;


int gameIsRunning;

int createWindow(void) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }
    
    window = SDL_CreateWindow("SDL Bird", 680, 480, 0);
    if (!window) {
        SDL_Log("Error setting up window: %s", SDL_GetError());
        return 0;
    }
    
    renderer = SDL_CreateRenderer(window, NULL);
    
    if (!renderer) {
        SDL_Log("Error setting up renderer: %s", SDL_GetError());
        return 0;
    }
    
    entities.push_back(pBackground);
    entities.push_back(pBird);
    entities.push_back(pCollisions);


    
    return 1;
}

void setup(void) {
    // std::list<Entity*>::iterator entity;
    // for(entity = entities.begin(); entity != entities.end(); entity++) {
    //     (*entity)->setup(window, renderer);
    // }
    collisions.setup(window, renderer);
    background.setup(window, renderer);
    bird.setup(window, renderer);

    collisions.addCollisionBox("birdCollisionBox", bird.frame);



    

}

/// Polls for user input and fires associated events
void pollInput(void) {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_EVENT_QUIT:
            gameIsRunning = 0;
            break;
        case SDL_EVENT_KEY_DOWN: case SDL_EVENT_FINGER_DOWN:
            bird.addUpwardVelocity();
            break;
    }
}

void update(void) {
    // Delays a set amount of time before continuing to render (standardizes FPS)
    SDL_Delay((Uint32) Constants::frameTargetTime);
    // std::list<Entity*>::iterator entity;
    // for(entity = entities.begin(); entity != entities.end(); entity++) {
    //     (*entity)->update();
    // }
    collisions.update();
    background.update();
    bird.update();


//     /* This all should be in bird.cpp at some point but it doesn't load correctly when it is */
    collisions.updateCollisionBoxPosition("birdCollisionBox", bird.frame.x, bird.frame.y);
    if(collisions.checkObjectCollision("birdCollisionBox") == "ceilingCollisionBox"){
       bird.frame.y = collisions.collisionBoxes["ceilingCollisionBox"].y + bird.frame.h;
    }
    if(collisions.checkObjectCollision("birdCollisionBox") == "groundCollisionBox"){
        bird.frame.y = collisions.collisionBoxes["groundCollisionBox"].y - (bird.frame.h);
        //eventually move groundcollisionbox down a ways and if they fly into it end the game.
    }
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 133, 43, 255, 0);
    SDL_RenderClear(renderer); //
        
    // std::list<Entity*>::iterator entity;
    // for(entity = entities.begin(); entity != entities.end(); entity++) {
    //     (*entity)->render(renderer);
    // }

    background.render(renderer);
    bird.render(renderer);
    collisions.render(renderer);


    
    SDL_RenderPresent(renderer); // Switches the back buffer with the screen to render it
}

void destroy(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int main(int argc, char *argv[]) {
    
    gameIsRunning = createWindow();
    setup();
    
    while (gameIsRunning) {
        pollInput();
        update();
        render();
    }
    
    destroy();
    return 0;
}
