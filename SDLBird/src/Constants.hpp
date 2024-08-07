//
//  Constants.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/19/24.
//

#ifndef Constants_hpp
#define Constants_hpp

#include <stdio.h>
#include <random>

namespace Constants {
    extern const float FPS;
    /// tick time in seconds
    extern float tickTimeSeconds;

    /// tick time in milliseconds
    extern float frameTargetTime;

    /// Generates a random float that is between two numbers
    float randFloat(float max, float min);
}


#endif /* Constants_hpp */
