#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "../../game_logic/src/logic.h"
#include "../../gui/src/gui_sdl.h"
#include "../../player/src/player.h"
#include "../../stats/src/stats.h"

extern uint8_t serialGlobal;

typedef struct game
{
  Player player;
  Ticket winningTicket;
} Game;

#endif
