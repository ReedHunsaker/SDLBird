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

std::string uint32ToHexString(uint32_t value) {
    std::ostringstream oss;
    oss << std::hex << std::setw(8) << std::setfill('0') << value;
    return oss.str();
}

std::string Constants::generateUUID() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 0xFFFFFFFF);

    // Generate random numbers for each part of the UUID
    uint32_t rnd1 = dis(gen);
    uint32_t rnd2 = dis(gen);
    uint32_t rnd3 = dis(gen);
    uint32_t rnd4 = dis(gen);

    // Format the UUID as a string
    std::stringstream ss;
    ss << uint32ToHexString(rnd1);
    ss << uint32ToHexString(rnd2);
    ss << uint32ToHexString(rnd3);
    ss << uint32ToHexString(rnd4);

    std::cout << ss.str() << std::endl;

    return ss.str();
}


