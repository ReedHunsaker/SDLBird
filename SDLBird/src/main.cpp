//
//  main.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 5/31/24.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

SDL_Window *window;
SDL_Renderer *renderer;
int gameIsRunning;

int createWindow(void) {
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }
    
    window = SDL_CreateWindow("SDL Bird", 680, 480, 0);
    if (!window) {
        fprintf(stderr, "Error setting up window");
        return 0;
    }
    renderer = SDL_CreateRenderer(window, NULL);
    
    if (!renderer) {
        fprintf(stderr, "Error setting up renderer");
        return 0;
    }
    
    return 1;
}

void setup(void) {
    
}

void pollInput(void) {
    SDL_Event event;
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_EVENT_QUIT:
            gameIsRunning = 0;
            break;
    }
}

void update(void) {
    
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 133, 43, 255, 0);
    SDL_RenderClear(renderer);
    
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    
    gameIsRunning = createWindow();
    setup();
    
    while (gameIsRunning) {
        pollInput();
        update();
        render();
    }
    return 0;
}
