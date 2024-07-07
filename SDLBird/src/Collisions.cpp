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

void Collisions::addCollisionBox(std::string obj_name, const SDL_FRect& box) {
    collisionBoxes[obj_name] = new SDL_FRect(box);
    std::cout << obj_name << std::endl;
}

void Collisions::removeCollisionBox(const std::string& name) {
    collisionBoxes.erase(name);
    std::cout << "Removed collision box for " << name << std::endl;
}

bool Collisions::checkCollisions() const {
    for (auto it1 = collisionBoxes.begin(); it1 != collisionBoxes.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != collisionBoxes.end(); ++it2) {
            // std::cout << "Checking collision between " << it1->first << " and " << it2->first << std::endl;
            if (SDL_HasRectIntersectionFloat((it1->second), (it2->second))) {
                std::cout << "Collision between " << it1->first << " and " << it2->first << std::endl;
                return true;
            }
        }
    }
    return false;
}

std::string Collisions::checkObjectCollision(std::string obj_name) {
    if (!obj_name.empty()) {
        for (auto it = collisionBoxes.begin(); it != collisionBoxes.end(); ++it){
            if(it->first != obj_name){
                // std::cout << "hit";
                if(SDL_HasRectIntersectionFloat(collisionBoxes[obj_name], it->second)){
                    std::cout << "Collision between " << obj_name << " and " << it->first << std::endl;
                    return it->first;
                }
            }
        }
    }
    return "";
}

void Collisions::updateCollisionBoxPosition(const std::string& obj_name, float new_x, float new_y) {
    auto it = collisionBoxes.find(obj_name);
    if (it != collisionBoxes.end() && it->second != nullptr) {
        it->second->x = new_x;
        it->second->y = new_y;
        // std::cout << "Updated collision box for " << obj_name << " to ("
                    // << new_x << ", " << new_y << ")" << std::endl;
    } else {
        std::cerr << "Collision box for " << obj_name << " not found!" << std::endl;
    }
}