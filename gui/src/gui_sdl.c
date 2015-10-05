#include "gui_sdl.h"

bool init()
{
  bool success = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("Failed to initialize!\nError: %s\n", SDL_GetError());
    success = false;
  }
  else
  {
    gWindow = SDL_CreateWindow("Lotto 7/39", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
              SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
      printf("Failed to create window!\nError: %s\n",SDL_GetError());
      success = false;
    }
    else
    {
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }

  return success;
}

void release()
{
  SDL_FreeSurface(gScreenSurface);
  SDL_DestroyWindow(gWindow);

  SDL_Quit();
}
