#include "stats.h"

uint8_t checkForMatches(Ticket* winningTicket,Ticket* ticket)
{
	uint8_t matches = 0;

	int i,j;
	for (i = 0; i < MAX_NUMBER; i++)
	{
		for (j = 0; j < MAX_NUMBER; j++)
		{
			if(winningTicket->numbers[i] == ticket->numbers[j])
			{
				matches++;
			}
		}
	}

	return matches;
}
