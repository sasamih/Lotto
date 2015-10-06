#include "logic.h"

void initialiseSerialGlobal()
{
  serialGlobal = 1;
}

void initialiseTicket(Ticket* ticket)
{
  ticket->serialNumber = serialGlobal++;
  ticket->currentNumber = 0;
}

bool writeDownNumber(Ticket* ticket, int8_t number)
{
  bool success = false;

  ticket->numbers[ticket->currentNumber++] = number;
  success = true;

  return success;
}
