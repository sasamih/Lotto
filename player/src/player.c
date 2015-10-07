#include "player.h"

void createPlayer(Player* player, char* pName)
{
	int length = strlen(pName) + 1;

	player->name = (char*) malloc(length * sizeof(char));

	int i = 0;
	for(i = 0; i < length; i++)
	{
		player->name[i] = pName[i];
	}
}