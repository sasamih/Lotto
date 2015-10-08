#include "logic.h"

static bool isNumberOnTicket(Ticket* ticket,int8_t number)
{
  bool success = false;

  int i;
  for(i = 0; i < ticket->currentNumber; i++)
  {
    if (ticket->numbers[i] == number)
    {
      success = true;
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

  if (ticket->currentNumber < MAX_NUMBER && !(isNumberOnTicket(ticket,number)))
  {
    ticket->numbers[ticket->currentNumber++] = number;
  }
  else
  {
    success = false;
  }

  return success;
}

bool deleteNumberFromTicket(Ticket* ticket,int8_t number)
{
   bool success = true;

   if((0 == ticket->currentNumber) || !(isNumberOnTicket(ticket, number)))
   {
     success = false;
   }
   else
   {
     int i = 0;
     int8_t tmp[ticket->currentNumber-1];
     while(number != ticket->numbers[i])
     {
       tmp[i] = ticket->numbers[i];
       i++;
     }
     i++;

     for(i;i < ticket->currentNumber; i++)
     {
       tmp[i-1] = ticket->numbers[i];
     }

     for(i = 0; i < ticket->currentNumber; i++)
     {
       ticket->numbers[i] = 0;
     }

     ticket->currentNumber--;
     for(i = 0; i < ticket->currentNumber;i++)
     {
       ticket->numbers[i] = tmp[i];
     }
   }

   return success;
}

void generateWinningTicket(Ticket* winningTicket)
{
  int i = 0;
  int8_t number;

  while(i < MAX_NUMBER)
  {
      number = (rand() % 39) + 1;
      if(!isNumberOnTicket(winningTicket,number))
      {
        winningTicket->numbers[i++] = number;
      }
  }
}
