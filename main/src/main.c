#include "main.h"

static void buttonPressed()
{
  columnNumber = e.button.x / NUMBER_WIDTH;
  rowNumber = e.button.y / NUMBER_HEIGHT;
  pickNumber.x = columnNumber * NUMBER_WIDTH;
  pickNumber.y = rowNumber * NUMBER_HEIGHT;
  pickNumber.w = NUMBER_WIDTH;
  pickNumber.h = NUMBER_HEIGHT;
}

static void printTicketNumbers(Ticket* ticket)
{
  int i;
  for(i = 0; i < ticket->currentNumber;i++)
    printf("%d ",ticket->numbers[i]);
  printf("\n");
}

int main(int argc, char* argv[])
{
  initialiseSerialGlobal();

  if (!init())
  {
    printf("Failed to initialize SDL. Error: %s\n", SDL_GetError());
  }
  else
  {
    if (!loadMedia() || !(loadGenerateButton()))
    {
      printf("Failed to load images! Error: %s\n",SDL_GetError());
    }
    else
    {
      bool quit = false;
      bool start = true;
      Ticket ticket;
      Ticket winningTicket;

      bool done = true;
      generatePressed = false;

      initialiseSerialGlobal();
      initialiseTicket(&ticket);
      initialiseTicket(&winningTicket);

      while(!quit)
      {
        while(SDL_PollEvent(&e) != 0)
        {
          if (SDL_QUIT == e.type)
          {
            quit = true;
          }
          SDL_FillRect(gScreenSurface,NULL,SDL_MapRGB(gScreenSurface->format,0xFF,0xFF,0xFF));
          SDL_Rect button = {GEN_BUTTON_X, GEN_BUTTON_Y, GEN_BUTTON_WIDTH, GEN_BUTTON_HEIGHT};
          SDL_BlitSurface(generateButton,NULL,gScreenSurface,&button);
           if (start)
           {
            fillAvailableNumbers();
            start = false;
           }
           else
           {
             if (SDL_MOUSEBUTTONDOWN == e.type)
             {
               if (SDL_BUTTON_LEFT == e.button.button)
               {
                 if (e.button.x < 280 && e.button.y < 240)
                 {
                   buttonPressed();
                   if (ticket.currentNumber < MAX_NUMBER)
                   {
                     pickSelectedNumber(&pickNumber,columnNumber,rowNumber);
                   }
                   done = writeDownNumber(&ticket, rowNumber*7+columnNumber+1);
                 }
                 else if(e.button.x > 300 && e.button.x < 600 && e.button.y < 90 && ticket.currentNumber == MAX_NUMBER)
                 {
                   generatePressed = !generatePressed;
                   loadTicket(&ticket);
                   initialiseTicket(&winningTicket);
                 }
               }
               else if (SDL_BUTTON_RIGHT == e.button.button)
               {
                 buttonPressed();
                 unpickSelectedNumber(&pickNumber,columnNumber,rowNumber);
                 done = deleteNumberFromTicket(&ticket,rowNumber*7+columnNumber+1);
               }
             }
             blitCurrentGrid();
             if(generatePressed)
             {
               printTicket();
               generateWinningTicket(&winningTicket);
               loadWinningTicket(&winningTicket);
               printWinningTicket();
               uint8_t matches = checkForMatches(&winningTicket,&ticket);
               printResult(matches);
             }
           }
          SDL_UpdateWindowSurface(gWindow);
        }
      }
    }
  }
  release();

  return 0;
}
