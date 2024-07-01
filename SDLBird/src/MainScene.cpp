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
    this->ceiling = Ceiling();
    this->ground = Ground();  
    
    this->addEntity(&background);
    this->addEntity(&ground);
    this->addEntity(&ceiling);
    this->addEntity(&bird);

}
