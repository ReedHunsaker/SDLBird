//
//  MainScene.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/27/24.
//

#ifndef MainScene_hpp
#define MainScene_hpp

#include <stdio.h>
#include <list>
#include "Bird.hpp"
#include "Background.hpp"
#include "Scene.hpp"
#include "Pipes.hpp"

class MainScene: public Scene {
    Background background;
    Bird bird;
    Pipes pipeOne;
    Pipes pipeTwo;
public:
    MainScene(SDL_Window *window, SDL_Renderer *renderer);
};

#endif /* MainScene_hpp */
