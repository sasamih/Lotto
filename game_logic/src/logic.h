#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <inttypes.h>

typedef struct ticket
{
    uint8_t serialNumber;
    int8_t numbers[7];
} Ticket;

#endif
