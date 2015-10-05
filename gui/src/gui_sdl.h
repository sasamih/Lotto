#ifndef GUI_SDL_H
#define GUI_SDL_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

bool init();
bool loadMedia();
void release();

#endif
