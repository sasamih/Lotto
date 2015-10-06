#include "../../unity/unity_fixture.h"
#include "../src/logic.h"

TEST_GROUP(LogicInitialiseTicket);
TEST_GROUP(LogicWriteDownNumber);

TEST_GROUP_RUNNER(LogicInitialiseTicket)
{
  RUN_TEST_CASE(LogicInitialiseTicket, SerialValue);
  RUN_TEST_CASE(LogicInitialiseTicket, CurrentNumber);
}

TEST_GROUP_RUNNER(LogicWriteDownNumber)
{
  RUN_TEST_CASE(LogicWriteDownNumber, AddFirstNumberToTicket);
  RUN_TEST_CASE(LogicWriteDownNumber, AddThreeNumbersToTicket);
  RUN_TEST_CASE(LogicWriteDownNumber, AddMaxNumbersToTicket);
  RUN_TEST_CASE(LogicWriteDownNumber, TicketFull);
  RUN_TEST_CASE(LogicWriteDownNumber, SameNumberTwice);
}

TEST_SETUP(LogicInitialiseTicket)
{
  initialiseSerialGlobal();
}

TEST_TEAR_DOWN(LogicInitialiseTicket)
{

}

TEST_SETUP(LogicWriteDownNumber)
{
  initialiseSerialGlobal();
}

TEST_TEAR_DOWN(LogicWriteDownNumber)
{

}

// ========================================================================= //

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
// ========================================================================= //

TEST(LogicWriteDownNumber, AddFirstNumberToTicket)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  writeDownNumber(&ticket, 2);
  TEST_ASSERT_EQUAL_INT8(1, ticket.currentNumber);
}

TEST(LogicWriteDownNumber, AddThreeNumbersToTicket)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  writeDownNumber(&ticket,1);
  writeDownNumber(&ticket,2);
  writeDownNumber(&ticket,35);

  TEST_ASSERT_EQUAL_INT8(3, ticket.currentNumber);
}

TEST(LogicWriteDownNumber, AddMaxNumbersToTicket)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  int i;
  for (i = 0; i < MAX_NUMBER; i++)
    writeDownNumber(&ticket,i+10);

  TEST_ASSERT_EQUAL_INT8(7, ticket.currentNumber);
}

TEST(LogicWriteDownNumber, TicketFull)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  int i;
  for (i = 0; i < MAX_NUMBER; i++)
    writeDownNumber(&ticket,i+10);

  writeDownNumber(&ticket, 35);

  TEST_ASSERT_EQUAL_INT8(7, ticket.currentNumber);
}

TEST(LogicWriteDownNumber, SameNumberTwice)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  writeDownNumber(&ticket, 2);
  writeDownNumber(&ticket, 2);

  TEST_ASSERT_EQUAL_INT8(1, ticket.currentNumber);
}
