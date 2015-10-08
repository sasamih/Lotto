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
    if (!loadMedia())
    {
      printf("Failed to load images! Error: %s\n",SDL_GetError());
    }
    else
    {
      bool quit = false;
      bool start = true;
      Ticket ticket;
      initialiseSerialGlobal();
      initialiseTicket(&ticket);
      bool done = true;

      while(!quit)
      {
        while(SDL_PollEvent(&e) != 0)
        {
          if (SDL_QUIT == e.type)
          {
            quit = true;
          }
          SDL_FillRect(gScreenSurface,NULL,SDL_MapRGB(gScreenSurface->format,0xFF,0xFF,0xFF));

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
                 buttonPressed();
                 pickSelectedNumber(&pickNumber,columnNumber,rowNumber);
                 done = writeDownNumber(&ticket, rowNumber*7+columnNumber+1);
               }
               else if (SDL_BUTTON_RIGHT == e.button.button)
               {
                 buttonPressed();
                 unpickSelectedNumber(&pickNumber,columnNumber,rowNumber);
                 done = deleteNumberFromTicket(&ticket,rowNumber*7+columnNumber+1);
               }
             }
             blitCurrentGrid();
           }
        //  SDL_BlitSurface(currentGrid,NULL,gScreenSurface,NULL);
          SDL_UpdateWindowSurface(gWindow);
        }
      }
    }
  }
  release();

  return 0;
}
