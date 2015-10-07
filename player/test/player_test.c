#include "../../unity/unity_fixture.h"
#include "../src/player.h"

TEST_GROUP(PlayerTest);

TEST_GROUP_RUNNER(PlayerTest)
{	
	RUN_TEST_CASE(PlayerTest, AssignNameToPlayer);
}

TEST_SETUP(PlayerTest)
{

}

TEST_TEAR_DOWN(PlayerTest)
{
  
}

TEST(PlayerTest, AssignNameToPlayer)
{
	Player player;
	createPlayer(&player, "name");
	STRCMP_EQUAL("name",player.name);
}