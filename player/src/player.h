#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct player
{
  char* name;
} Player;

void createPlayer(Player* player,char* pName);

#endif
