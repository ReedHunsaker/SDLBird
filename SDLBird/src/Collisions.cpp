//
//  Collisions.cpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/20/24.
//

#include "Collisions.hpp"
#include <iostream>

Collisions::Collisions() {}

SDL_FRect Collisions::createCollisionBox(float x, float y, float w, float h) {
    SDL_FRect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    return rect;
}

void Collisions::addCollisionBox(std::string obj_tag, const SDL_FRect& box) {
    collisionBoxes[obj_tag] = box;
    std::cout << obj_tag << std::endl;
}

bool Collisions::checkCollisions() const {
    for (auto it1 = collisionBoxes.begin(); it1 != collisionBoxes.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != collisionBoxes.end(); ++it2) {
            if (SDL_HasRectIntersectionFloat(&(it1->second), &(it2->second))) {
                std::cout << "Collision between " << it1->first << " and " << it2->first << std::endl;
                return true;
            }
        }
    }
    return false;
}

void Collisions::updateCollisionBoxPosition(const std::string& obj_tag, float new_x, float new_y) {
    std::cout << obj_tag << " " << new_x << " " << new_y << std::endl;
    // if (collisionBoxes.count(obj_tag)) {
        collisionBoxes[obj_tag].x = new_x;
        collisionBoxes[obj_tag].y = new_y;
    // } else {
    //     std::cerr << "Error: No collision box found for tag " << obj_tag << std::endl;
    // }
}

void Collisions::setup(SDL_Window* window, SDL_Renderer* renderer) {
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    groundCollisionBox = createCollisionBox(0.0f, static_cast<float>(windowHeight - 5), static_cast<float>(windowWidth), 5.0f);
    ceilingCollisionBox = createCollisionBox(0.0f, 0.0f, static_cast<float>(windowWidth), 5.0f);

    addCollisionBox("groundCollisionBox", groundCollisionBox);
    addCollisionBox("ceilingCollisionBox", ceilingCollisionBox);


}

void Collisions::update() {
    checkCollisions();
}

void Collisions::render(SDL_Renderer* renderer) {
    // Render other collision boxes (if needed)
    if(renderCollisionBoxes){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (const auto& box : collisionBoxes) {
            if (SDL_RenderFillRect(renderer, &box.second) != 0) {
                SDL_Log("Error drawing collisionBox: %s", SDL_GetError());
            }
        }
    }
}