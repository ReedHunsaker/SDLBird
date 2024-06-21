//
//  Collisions.hpp
//  SDLBird
//
//  Created by Joshua hunsaker on 6/20/24.
//

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <unordered_map>
#include "Entity.hpp"

#ifndef Collisions_hpp
#define Collisions_hpp

class Collisions: public Entity {
    

    

public:
    std::unordered_map<std::string, SDL_FRect> collisionBoxes;
    Collisions();

    SDL_FRect createCollisionBox(float x, float y, float w, float h);
    void addCollisionBox(std::string obj_tag, const SDL_FRect& box);
    bool checkCollisions() const;
    std::string checkObjectCollision(std::string obj_tag);
    void updateCollisionBoxPosition(const std::string& obj_tag, float new_x, float new_y);

    void setup(SDL_Window* window, SDL_Renderer* renderer);
    void update();
    void render(SDL_Renderer* renderer);

    private:
        SDL_FRect groundCollisionBox;
        SDL_FRect ceilingCollisionBox;
        bool renderCollisionBoxes = false;

};

#endif /* Collisions_hpp */
