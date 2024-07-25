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
    this->pipeOne = Pipes();
    this->pipeTwo = Pipes();
    this->score = Text();
    
    pipeOne.score = &score;
    pipeTwo.score = &score;
    
    pipeOne.player = &bird;
    pipeTwo.player = &bird;
    
    int windowWidth = 0;
    int *pWindowWidth = &windowWidth;
    if (SDL_GetWindowSize(window, pWindowWidth, NULL) != 0) {
        SDL_Log("Error getting window size: %s", SDL_GetError());
        *pWindowWidth = 0;
    }
    pipeOne.setSpawnOffset(0);
    pipeTwo.setSpawnOffset((*pWindowWidth * 0.5) + pipeTwo.pipeWidth);
    
    score.setText("0");
    
    SDL_Color black = {0, 0, 0};
    score.setTextColor(black);
    this->ceiling = Ceiling();
    this->ground = Ground();
    this->addEntity(&background);
    this->addEntity(&ground);
    this->addEntity(&ceiling);
    this->addEntity(&bird);
    this->addEntity(&pipeOne);
    this->addEntity(&pipeTwo);
    this->addEntity(&score);

}
