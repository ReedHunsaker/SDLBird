//
//  Text.hpp
//  SDLBird
//
//  Created by Reed hunsaker on 7/8/24.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include "Entity.hpp"
#include "string"
#include "SDL3_ttf/SDL_ttf.h"

class Text: public Entity {
    TTF_Font* font;
    SDL_Color textColor = { 0x00, 0x00, 0x00, 0 };
    std::string text;
    int width;
    int height;
    int windowWidth;
    int fontSize;
    std::string fontFamily;
public:
    Text();
    void setup(SDL_Window *window, SDL_Renderer *renderer) override;
    void input(Uint32 eventType) override;
    void update() override;
    void render(SDL_Renderer *renderer) override;
    
    void setText(std::string text);
    void setTextColor(SDL_Color color);
    void setFont(std::string fontName, int fontSize);
};

#endif /* Text_hpp */
