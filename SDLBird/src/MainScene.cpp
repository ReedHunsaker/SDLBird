//
//  MainScene.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 6/27/24.
//

#include "MainScene.hpp"

MainScene::MainScene(SDL_Window *window, SDL_Renderer *renderer): Scene(window, renderer) {
    this->bird = Bird();
    this->background = Background();
    
    this->addEntity(&background);
    this->addEntity(&bird);
}
