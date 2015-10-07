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
  bool success = true;

  int i;
  for(i = 0; i < ticket->currentNumber; i++)
  {
    if (ticket->numbers[i] == number)
    {
      success = false;
      break;
    }
  }

  if (ticket->currentNumber < MAX_NUMBER && success != false)
  {
    ticket->numbers[ticket->currentNumber++] = number;
  }

  return success;
}
