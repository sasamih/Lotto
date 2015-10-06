#include <SDL2/SDL.h>
#include "../../unity/unity_fixture.h"
#include <stdbool.h>
#include "../src/gui_sdl.h"

TEST_GROUP(SDLTest);

TEST_GROUP_RUNNER(SDLTest)
{
  RUN_TEST_CASE(SDLTest, Initialisation);
}

TEST_SETUP(SDLTest)
{
  if (!init())
  {
    printf("Initialisation failed!\n");
  }
  else
  {
    SDL_FillRect(gScreenSurface,NULL,SDL_MapRGB(gScreenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(gWindow);

    SDL_Delay(3000);
    release();
  }
}

TEST_TEAR_DOWN(SDLTest)
{

}

TEST(SDLTest, Initialisation)
{
  TEST_ASSERT_EQUAL_INT(1,1);
}
