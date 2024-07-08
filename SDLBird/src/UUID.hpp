//
//  UUID.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 7/7/24.
//

#ifndef UUID_hpp
#define UUID_hpp

#include <stdio.h>
#include <stdio.h>
#include <random>
#include <iomanip>
#include <sstream>
#include <iostream>

struct UUID {
    std::string id;
};

UUID generateUUID();
#endif /* UUID_hpp */
