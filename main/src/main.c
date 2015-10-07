#include "main.h"

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
      SDL_Event e;
      SDL_Rect pickNumber;

      uint8_t rowNumber;
      uint8_t columnNumber;

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
                 columnNumber = e.button.y / NUMBER_WIDTH;
                 rowNumber = e.button.x / NUMBER_HEIGHT;
                 pickNumber.x = columnNumber * NUMBER_WIDTH;
                 pickNumber.y = rowNumber * NUMBER_HEIGHT;
                 pickNumber.w = NUMBER_WIDTH;
                 pickNumber.h = NUMBER_HEIGHT;

                 pickSelectedNumber(&pickNumber,columnNumber,rowNumber);
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
