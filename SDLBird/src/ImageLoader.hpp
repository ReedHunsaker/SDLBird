//
//  ImageLoader.h
//  SDLBird
//
//  Created by Reed hunsaker on 6/18/24.
//

#ifndef ImageLoader_h
#define ImageLoader_h

#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

SDL_Texture *loadImage(SDL_Renderer *renderer, const char *file);

#endif /* ImageLoader_h */
