//
//  MainScene.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/27/24.
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include "Bird.hpp"
#include "Background.hpp"
#include "Scene.hpp"

class MainScene: public Scene {
    Background background;
    Bird bird;
public:
    MainScene(SDL_Window *window, SDL_Renderer *renderer);
};

#endif /* MainScene_hpp */
