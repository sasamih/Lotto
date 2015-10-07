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
    SDL_FillRect(gScreenSurface,NULL,SDL_MapRGB(gScreenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(gWindow);

    SDL_Delay(3000);
    release();
  }

  return 0;
}
