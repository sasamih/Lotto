#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define MAX_NUMBER 7

uint8_t serialGlobal;

typedef struct ticket
{
    uint8_t serialNumber;
    int8_t numbers[MAX_NUMBER];
    int8_t currentNumber;
} Ticket;

void initialiseSerialGlobal();
void initialiseTicket(Ticket* ticket);
bool writeDownNumber(Ticket* ticket, int8_t number);
bool deleteNumberFromTicket(Ticket* ticket,int8_t number);
void generateWinningTicket(Ticket* winningTicket);

#endif
