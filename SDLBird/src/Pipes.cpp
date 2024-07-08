//
//  Pipes.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/26/24.
//


#include "Pipes.hpp"

Pipes::Pipes() {
    pipeGap = 175;
    pipeSpeed = 2.5; // Matches background speed
    pipeWidth = 82;
    didStart = false;
    randomOffset = 0;
    spawnOffset = 0;
}

void Pipes::setSpawnOffset(float offset) {
    spawnOffset = offset;
}

void Pipes::setup(SDL_Window *window, SDL_Renderer *renderer) {
    this->window = window;
    this->renderer = renderer;
    id = generateUUID().id;
    resetPipes(spawnOffset);

    Collisions::getInstance().addCollisionBox(id, {bottomPipeFrame, topPipeFrame});
    std::cout << id << std::endl;
}

void Pipes::resetPipes(float spawnOffset) {
    int *x = &windowWidth, *y = &windowHeight;
    if (SDL_GetWindowSize(window, x, y) != 0) {
        SDL_Log("Error getting window size: %s", SDL_GetError());
        *x = 0;
        *y = 0;
    }

    topPipeTexture = loadImage(renderer, "pipe.png");
    bottomPipeTexture = loadImage(renderer, "pipe.png");

    float maxOffset = *y * 0.25;
    float minOffset = -*y * 0.25;
    randomOffset = Constants::randFloat(maxOffset, minOffset);

    float xSpawnPoint = *x + 52 + spawnOffset;

    // The top left corner is located at the midY point - half the pipe gap
    // Bottom pipe positioning
    bottomPipeFrame.h = *y;
    bottomPipeFrame.w = pipeWidth;
    bottomPipeFrame.y = (*y * 0.5) + (pipeGap * 0.5) + randomOffset;
    bottomPipeFrame.x = xSpawnPoint;

    // Top pipe positioning
    topPipeFrame.h = *y;
    topPipeFrame.w = pipeWidth;
    topPipeFrame.y = (*y * 0.5) - (pipeGap * 0.5) - topPipeFrame.h + randomOffset;  //changed from  topPipeFrame.y = (*y * 0.5) - (pipeGap * 0.5) + randomOffset;
    topPipeFrame.x = xSpawnPoint;  //changed from topPipeFrame.x = xSpawnPoint + pipeWidth;
}

void Pipes::start() {
    didStart = true;    
}

void Pipes::update() {
    if (!didStart) {
        return;
    }
    bottomPipeFrame.x -= pipeSpeed;
    topPipeFrame.x -= pipeSpeed;
    if (bottomPipeFrame.x < -pipeWidth) {
        resetPipes(0);
    }

    Collisions::getInstance().updateCollisionBoxPosition(id, 0, bottomPipeFrame.x, bottomPipeFrame.y);
    Collisions::getInstance().updateCollisionBoxPosition(id, 1, topPipeFrame.x, topPipeFrame.y);
}

void Pipes::input(Uint32 eventType) {
    switch (eventType) {
        case SDL_EVENT_KEY_DOWN:
        case SDL_EVENT_FINGER_DOWN:
            start();
            break;
    }
}

void Pipes::render(SDL_Renderer *renderer) {
    if (SDL_RenderTexture(renderer, bottomPipeTexture, NULL, &bottomPipeFrame) != 0) {
        SDL_Log("Error drawing bottom pipe texture: %s", SDL_GetError());
        return;
    }

    if (SDL_RenderTextureRotated(renderer, topPipeTexture, NULL, &topPipeFrame, 0, NULL, SDL_FLIP_VERTICAL) != 0) {
        SDL_Log("Error drawing top pipe texture: %s", SDL_GetError());
        return;
    }
    Collisions::getInstance().renderCollisionBox(renderer, id, 0);
    Collisions::getInstance().renderCollisionBox(renderer, id, 1);
}
