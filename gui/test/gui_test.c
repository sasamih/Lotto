#include <SDL2/SDL.h>
#include "../../unity/unity_fixture.h"
#include <stdbool.h>
#include "../src/gui_sdl.h"

TEST_GROUP(SDLTest);

TEST_GROUP_RUNNER(SDLTest)
{
  RUN_TEST_CASE(SDLTest, Initialisation);
  RUN_TEST_CASE(SDLTest, LoadMedia);
  RUN_TEST_CASE(SDLTest, LoadAvailableNumbers);
  RUN_TEST_CASE(SDLTest, LoadPickedNumbers);
}

TEST_SETUP(SDLTest)
{

}

TEST_TEAR_DOWN(SDLTest)
{

}

TEST(SDLTest, Initialisation)
{
  TEST_ASSERT_TRUE(true == init())
}

TEST(SDLTest, LoadMedia)
{
  init();
  TEST_ASSERT_TRUE(true == loadMedia());
}

TEST(SDLTest, LoadAvailableNumbers)
{
  init();
  TEST_ASSERT_TRUE(true == loadMedia());
}

TEST(SDLTest, LoadPickedNumbers)
{
  init();
  TEST_ASSERT_TRUE(true == loadMedia());
}
