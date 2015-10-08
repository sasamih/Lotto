#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <time.h>
#include "../../game_logic/src/logic.h"
#include "../../gui/src/gui_sdl.h"
#include "../../player/src/player.h"
#include "../../stats/src/stats.h"

extern uint8_t serialGlobal;
SDL_Event e;
SDL_Rect pickNumber;

bool generatePressed;
uint8_t rowNumber;
uint8_t columnNumber;

typedef struct game
{
  Player player;
  Ticket winningTicket;
} Game;

#endif
