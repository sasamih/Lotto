#ifndef GUI_SDL_H
#define GUI_SDL_H

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../../game_logic/src/logic.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TOTAL_NUMBERS 39
#define NUMBER_WIDTH 40
#define NUMBER_HEIGHT 40
#define GEN_BUTTON_X 300
#define GEN_BUTTON_Y 0
#define GEN_BUTTON_WIDTH 300
#define GEN_BUTTON_HEIGHT 90

SDL_Window* gWindow;
SDL_Surface* gScreenSurface;
SDL_Surface* availableNumbers[TOTAL_NUMBERS];
SDL_Surface* pickedNumber[TOTAL_NUMBERS];
SDL_Surface* currentGrid[TOTAL_NUMBERS];
SDL_Surface* generateButton;
SDL_Surface* ticketImage[MAX_NUMBER];

bool init();
bool loadMedia();
bool loadGenerateButton();
void loadTicket(Ticket* ticket);
void fillAvailableNumbers();
void blitCurrentGrid();
void pickSelectedNumber(SDL_Rect* pickNumber,int columnNumber,int rowNumber);
void unpickSelectedNumber(SDL_Rect* unpickNumber,int columnNumber,int rowNumber);
void release();

#endif
