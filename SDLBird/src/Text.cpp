//
//  Text.cpp
//  SDLBird
//
//  Created by Reed hunsaker on 7/8/24.
//

#include "Text.hpp"

Text::Text() {
    windowWidth = 0;
    width = 100;
    height = 100;
    text = "";
    fontSize = 32;
    fontFamily = "ruba.ttf";
    font = TTF_OpenFont(fontFamily.c_str(), fontSize);
    if (font == NULL) {
        SDL_Log("Error creating font: %s", SDL_GetError());
    }
    frame.y = 64;
}

void Text::setup(SDL_Window *window, SDL_Renderer *renderer) {
    int *pWindowWidth = &windowWidth;
    if (SDL_GetWindowSize(window, pWindowWidth, NULL) != 0) {
        SDL_Log("Error getting window size: %s", SDL_GetError());
        *pWindowWidth = 0;
    }
}

void Text::input(Uint32 eventType) {}

void Text::update() {
    frame.w = width;
    frame.h = height;
    frame.x = (windowWidth * 0.5) - (width * 0.5);
}

void Text::render(SDL_Renderer *renderer) {
    SDL_Surface* sufaceText =
        TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, sufaceText);
    if (SDL_RenderTexture(renderer, textureText, NULL, &frame) != 0) {
        SDL_Log("Error rendering text: %s", SDL_GetError());
    }
}

void Text::setText(std::string text) {
    this->text = text;
    TTF_SizeText(font, text.c_str(), &width, &height);
}

void Text::setTextColor(SDL_Color color) {
    this->textColor = color;
}

void Text::setFont(std::string fontName, int fontSize) {
    this->fontFamily = fontName;
    this->fontSize = fontSize;
    font = TTF_OpenFont(fontFamily.c_str(), fontSize);
}
