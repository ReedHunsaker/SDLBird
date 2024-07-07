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

void Collisions::addCollisionBox(std::string obj_name, const std::vector<SDL_FRect>& boxes) {
    collisionBoxes[obj_name] = boxes;
    std::cout << obj_name << std::endl;
}

void Collisions::removeCollisionBox(const std::string& name) {
    collisionBoxes.erase(name);
    std::cout << "Removed collision box for " << name << std::endl;
}

bool Collisions::checkCollisions() const {
    for (auto it1 = collisionBoxes.begin(); it1 != collisionBoxes.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != collisionBoxes.end(); ++it2) {
            for (const auto& box1 : it1->second) {
                for (const auto& box2 : it2->second) {
                    if (SDL_HasRectIntersectionFloat(&box1, &box2)) {
                        std::cout << "Collision between " << it1->first << " and " << it2->first << std::endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

std::string Collisions::checkObjectCollision(const std::string obj_name) {
    if (collisionBoxes.find(obj_name) != collisionBoxes.end()) {
        for (auto it = collisionBoxes.begin(); it != collisionBoxes.end(); ++it) {
            if (it->first != obj_name) {
                for (const auto& box1 : collisionBoxes[obj_name]) {
                    for (const auto& box2 : it->second) {
                        if (SDL_HasRectIntersectionFloat(&box1, &box2)) {
                            std::cout << "Collision between " << obj_name << " and " << it->first << std::endl;
                            return it->first;
                        }
                    }
                }
            }
        }
    }
    return "";
}

void Collisions::updateCollisionBoxPosition(const std::string& obj_name, size_t index, float new_x, float new_y) {
    auto it = collisionBoxes.find(obj_name);
    if (it != collisionBoxes.end() && index < it->second.size()) {
        it->second[index].x = new_x;
        it->second[index].y = new_y;
        // std::cout << "Updated collision box for " << obj_name << " at index " << index << " to ("
        //           << new_x << ", " << new_y << ")" << std::endl;
    } else {
        std::cerr << "Collision box for " << obj_name << " at index " << index << " not found!" << std::endl;
    }
}

void Collisions::renderCollisionBox(SDL_Renderer* renderer, const std::string& obj_name, size_t index) {
    auto it = collisionBoxes.find(obj_name);
    if (it != collisionBoxes.end() && index < it->second.size()) {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Enable blending mode
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 128); // Red color with 50% transparency

        SDL_FRect drawBox = it->second[index];
        SDL_RenderFillRect(renderer, &drawBox); // Draw the rectangle with transparency

        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE); // Reset blend mode to default
    } else {
        std::cerr << "Collision box for " << obj_name << " at index " << index << " not found!" << std::endl;
    }
}