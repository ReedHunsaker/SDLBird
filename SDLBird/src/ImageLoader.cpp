//
//  ImageLoader.c
//  SDLBird
//
//  Created by Reed hunsaker on 6/18/24.
//

#include "ImageLoader.hpp"

#define WINDOWS_PATH "./resources/"

SDL_Texture *loadImage(SDL_Renderer *renderer, const char *file) {
#ifdef __APPLE__
    SDL_Texture *texture = IMG_LoadTexture(renderer, file);
#endif
#ifdef _WIN32
    char fullPath[256];
    strcpy(fullPath, WINDOWS_PATH);
    strcat(fullPath, file);
    SDL_Texture *texture = IMG_LoadTexture(renderer, fullPath);
#endif
    if (texture == NULL) {
        SDL_Log("Error loading texture from file %s with error %s", file, SDL_GetError());
        return NULL;
    }
    
    return texture;
}
