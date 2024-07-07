//
//  main.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 5/31/24.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "MainScene.hpp"

SDL_Window *window;
SDL_Renderer *renderer;

Collisions collisions;
Bird bird;

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
        
    return 1;
}

void setup(Scene *scene) {
    
    scene->setup();

}

/// Polls for user input and fires associated events
void pollInput(Scene *scene) {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_EVENT_QUIT:
            gameIsRunning = 0;
            break;
    }
    scene->input(event.type);
}

void update(Scene *scene) {
    // Delays a set amount of time before continuing to render (standardizes FPS)
    SDL_Delay((Uint32) Constants::frameTargetTime);
    scene->update();

}

void render(Scene *scene) {
    scene->render();
    
    SDL_RenderPresent(renderer); // Switches the back buffer with the screen to render it
}

void destroy(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int main(int argc, char *argv[]) {
    
    gameIsRunning = createWindow();
    Scene scene = MainScene(window, renderer);
    setup(&scene);
    
    while (gameIsRunning) {
        pollInput(&scene);
        update(&scene);
        render(&scene);
    }
    
    destroy();
    return 0;
}
