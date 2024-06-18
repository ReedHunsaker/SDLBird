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

SDL_Window *window;
SDL_Renderer *renderer;
Bird bird = Bird();
Background background = Background();

int gameIsRunning;
Uint64 lastFrameTime = 0;

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

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
    
    return 1;
}

void setup(void) {
    bird.setup(window, renderer);
    background.setup(window, renderer);
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
    SDL_Delay((Uint32) FRAME_TARGET_TIME);
    lastFrameTime = SDL_GetTicks();
    background.update();
    bird.update();
    
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 133, 43, 255, 0);
    SDL_RenderClear(renderer); //

    background.render(renderer);
    bird.render(renderer);
    
    
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
