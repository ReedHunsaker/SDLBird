//
//  UUID.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 7/7/24.
//

#include "UUID.hpp"

std::string uint32ToHexString(uint32_t value) {
    std::ostringstream oss;
    oss << std::hex << std::setw(8) << std::setfill('0') << value;
    return oss.str();
}

UUID generateUUID() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 0xFFFFFFFF);

    // Generate random numbers for each part of the UUID
    uint32_t rnd1 = dis(gen);
    uint32_t rnd2 = dis(gen);
    uint32_t rnd3 = dis(gen);
    uint32_t rnd4 = dis(gen);

    // Format the UUID as a string
    std::string ss;
    ss += uint32ToHexString(rnd1);
    ss += uint32ToHexString(rnd2);
    ss += uint32ToHexString(rnd3);
    ss += uint32ToHexString(rnd4);

    std::cout << ss << std::endl;

    return { .id = ss };
}
