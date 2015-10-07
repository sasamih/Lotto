#ifndef GUI_SDL_H
#define GUI_SDL_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TOTAL_NUMBERS 39
#define NUMBER_WIDTH 40
#define NUMBER_HEIGHT 40

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* availableNumbers[TOTAL_NUMBERS];
SDL_Surface* pickedNumber[TOTAL_NUMBERS];

bool init();
bool loadMedia();
void release();

#endif
