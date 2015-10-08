#include "../../unity/unity_fixture.h"
#include "../src/stats.h"
#include "../../game_logic/src/logic.h"

TEST_GROUP(StatsTest);

TEST_GROUP_RUNNER(StatsTest)
{
	RUN_TEST_CASE(StatsTest, NumberOfMatches);
}

TEST_SETUP(StatsTest)
{
	initialiseSerialGlobal();
}

TEST_TEAR_DOWN(StatsTest)
{

}

TEST(StatsTest, NumberOfMatches)
{
	Ticket ticket,winningTicket;

	initialiseTicket(&ticket);
	initialiseTicket(&winningTicket);

	writeDownNumber(&ticket,1);
	writeDownNumber(&ticket,13);
	writeDownNumber(&ticket,7);
	writeDownNumber(&ticket,4);
	writeDownNumber(&ticket,33);
	writeDownNumber(&ticket,29);
	writeDownNumber(&ticket,18);

	writeDownNumber(&winningTicket,7);
	writeDownNumber(&winningTicket,5);
	writeDownNumber(&winningTicket,34);
	writeDownNumber(&winningTicket,29);
	writeDownNumber(&winningTicket,13);
	writeDownNumber(&winningTicket,15);
	writeDownNumber(&winningTicket,27);

	TEST_ASSERT_EQUAL_UINT8(3, checkForMatches(&winningTicket,&ticket));
}