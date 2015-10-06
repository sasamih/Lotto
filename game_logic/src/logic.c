#include "logic.h"

void initialiseSerialGlobal()
{
  serialGlobal = 1;
}

void initialiseTicket(Ticket* ticket)
{
  ticket->serialNumber = serialGlobal;
  ticket->currentNumber = 0;
}
