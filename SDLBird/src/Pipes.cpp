//
//  Pipes.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/26/24.
//

#include "Pipes.hpp"

Pipes::Pipes() {
    pipeGap = 200;
    pipeSpeed = 1;
    didStart = false;
}

void Pipes::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int windowWidth = 0;
    int windowHeight = 0;
    int *x = &windowWidth, *y = &windowHeight;
    
    if (SDL_GetWindowSize(window, x, y) != 0) {
        SDL_Log("Error getting window size: %s", SDL_GetError());
        *x = 0;
        *y = 0;
    }
    topPipeTexture = loadImage(renderer, "pipe.png");
    bottomPipeTexture = loadImage(renderer, "pipe.png");
    
    // The top left corner is located at the midY point - half the pipe gap
    bottomPipeFrame.h = *y;
    bottomPipeFrame.w = 82;
    bottomPipeFrame.y = (*y * 0.5) - (pipeGap * 0.5);
    bottomPipeFrame.x = *x + 52;
}

void Pipes::start() {
    didStart = true;
}

void Pipes::update() {
    // guard statement
    if (!didStart) { return; }
    bottomPipeFrame.x -= pipeSpeed;
}

void Pipes::render(SDL_Renderer *renderer) {
    if (SDL_RenderTexture(renderer, bottomPipeTexture, NULL, &bottomPipeFrame) != 0) {
        SDL_Log("Error drawing texture: %s", SDL_GetError());
        return;
    }
//    if(SDL_RenderTextureRotated(renderer, topPipeTexture,
//                                NULL, &topPipeFrame,
//                                0, &topPipeFrame, SDL_FLIP_VERTICAL)) {
//        SDL_Log("Error drawing texture: %s", SDL_GetError());
//        return;
//    }
}
