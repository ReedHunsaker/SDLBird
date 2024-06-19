//
//  Bird.cpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/18/24.
//

#include "Background.hpp"

Background::Background() {}

void Background::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int windowWidth = 0;
    int windowHeight = 0;
    int *x = &windowWidth, *y = &windowHeight;
    
    texture = getBackgroundTexture(renderer);

    if (SDL_GetWindowSize(window, x, y) != 0) {
        SDL_Log("Error getting window size: %s", SDL_GetError());
        *x = 0;
        *y = 0;
    }

    frame1 = SDL_FRect();
    frame2 = SDL_FRect();
    
    frame1.h = frame2.h = (float) *y;
    frame1.w = frame2.w = (float) *x;

    // Set the initial positions
    frame1.x = 0;
    frame1.y = 0;
    frame2.x = (float) *x; // frame2 starts right after frame1
    frame2.y = 0;
}

void Background::update() {
    frame1.x -= background_speed;
    frame2.x -= background_speed;

    // Reset positions when they go off-screen
    if (frame1.x + frame1.w <= 0) {
        frame1.x = frame2.x + frame2.w;
    }
    if (frame2.x + frame2.w <= 0) {
        frame2.x = frame1.x + frame1.w;
    }
}

void Background::render(SDL_Renderer *renderer) {
    if (SDL_RenderTexture(renderer, texture, NULL, &frame1) != 0) {
        SDL_Log("Error drawing texture (frame1): %s", SDL_GetError());
        return;
    }
    if (SDL_RenderTexture(renderer, texture, NULL, &frame2) != 0) {
        SDL_Log("Error drawing texture (frame2): %s", SDL_GetError());
        return;
    }
}

SDL_Texture *Background::getBackgroundTexture(SDL_Renderer *renderer) {
#ifdef __APPLE__
    return IMG_LoadTexture(renderer, "backgroundPortrait.png");
#endif
#ifdef _WIN32
    return IMG_LoadTexture(renderer, "backgroundLandscape.png");
#endif
}
