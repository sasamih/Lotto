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
      SDL_Event e;

      while(!quit)
      {
        while(SDL_PollEvent(&e) != 0)
        {
          if (SDL_QUIT == e.type)
          {
            quit = true;
          }

          SDL_FillRect(gScreenSurface,NULL,SDL_MapRGB(gScreenSurface->format,0xFF,0xFF,0xFF));
          SDL_UpdateWindowSurface(gWindow);
        }
      }
    }
  }
  release();

  return 0;
}
