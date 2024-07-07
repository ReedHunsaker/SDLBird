//
//  Collisions.hpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/20/24.
//

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <unordered_map>
#include <vector>
#include "Entity.hpp"

#ifndef Collisions_hpp
#define Collisions_hpp

class Collisions{

public:

    // Delete copy constructor and assignment operator
    Collisions(const Collisions&) = delete;
    Collisions& operator=(const Collisions&) = delete;

    // Static method to access the single instance
    static Collisions& getInstance() {
        static Collisions instance;
        return instance;
    }

    std::unordered_map<std::string, std::vector<SDL_FRect>> collisionBoxes;
    Collisions();

    //create a collision box if the object has no SDL_FRect render frame
    SDL_FRect createCollisionBox(float x, float y, float w, float h);

    //remove a collision box
    void removeCollisionBox(const std::string& name);

    //attach the collision box to an object, often object frames can be used as the collision box
    void addCollisionBox(std::string obj_tag, const std::vector<SDL_FRect>& box);

    //will check all collisions of all objects
    bool checkCollisions() const;

    //will check all collisions happening to a specific object
    std::string checkObjectCollision(const std::string obj_tag);

    //update the collision box positiion
    void updateCollisionBoxPosition(const std::string& obj_tag, size_t index, float new_x, float new_y);

    void renderCollisionBox(SDL_Renderer* renderer, const std::string& obj_name, size_t index);

};

#endif /* Collisions_hpp */
