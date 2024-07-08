//
//  Constants.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/19/24.
//

#include "Constants.hpp"

const float Constants::FPS = 60;

float Constants::tickTimeSeconds = 1 / FPS;

float Constants::frameTargetTime = 1000 / FPS;

float Constants::randFloat(float max, float min) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);

    // Generate a random float
    return dist(gen);
}


