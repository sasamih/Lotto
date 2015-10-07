#include "logic.h"

static bool isNumberOnTicket(Ticket* ticket,int8_t number)
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

  return success;
}

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

  if (ticket->currentNumber < MAX_NUMBER && isNumberOnTicket(ticket,number))
  {
    ticket->numbers[ticket->currentNumber++] = number;
  }
  else
  {
    success = false;
  }

  return success;
}
