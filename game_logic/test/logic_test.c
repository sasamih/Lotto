#include "../../unity/unity_fixture.h"
#include "../src/logic.h"

TEST_GROUP(LogicInitialiseTicket);

TEST_GROUP_RUNNER(LogicInitialiseTicket)
{
  RUN_TEST_CASE(LogicInitialiseTicket, SerialValue);
  RUN_TEST_CASE(LogicInitialiseTicket, CurrentNumber);
}

TEST_SETUP(LogicInitialiseTicket)
{
  initialiseSerialGlobal();
}

TEST_TEAR_DOWN(LogicInitialiseTicket)
{

}

TEST(LogicInitialiseTicket, SerialValue)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  TEST_ASSERT_EQUAL_UINT8(1, ticket.serialNumber);
}

TEST(LogicInitialiseTicket, CurrentNumber)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  TEST_ASSERT_EQUAL_INT8(0, ticket.currentNumber);
}
