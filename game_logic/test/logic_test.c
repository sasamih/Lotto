#include "../../unity/unity_fixture.h"
#include "../src/logic.h"

TEST_GROUP(LogicInitialiseTicket);
TEST_GROUP(LogicWriteDownNumber);
TEST_GROUP(LogicDeleteNumber);

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

TEST_GROUP_RUNNER(LogicDeleteNumber)
{
  RUN_TEST_CASE(LogicDeleteNumber, TicketEmpty);
  RUN_TEST_CASE(LogicDeleteNumber, NonExistingNumberOnTicket);
  RUN_TEST_CASE(LogicDeleteNumber, DeleteNumberFromTicket);
  RUN_TEST_CASE(LogicDeleteNumber, IsCurrentNumberDecremented);
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

TEST_SETUP(LogicDeleteNumber)
{
  initialiseSerialGlobal();
}

TEST_TEAR_DOWN(LogicDeleteNumber)
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

// ========================================================================= //

TEST(LogicDeleteNumber, TicketEmpty)
{
  Ticket ticket;
  initialiseTicket(&ticket);

  TEST_ASSERT_TRUE(false == deleteNumberFromTicket(&ticket, 2));
}

TEST(LogicDeleteNumber, NonExistingNumberOnTicket)
{
  Ticket ticket;
  initialiseTicket(&ticket);
  writeDownNumber(&ticket,2);
  writeDownNumber(&ticket,3);

  TEST_ASSERT_TRUE(false == deleteNumberFromTicket(&ticket, 4));
}

TEST(LogicDeleteNumber, DeleteNumberFromTicket)
{
  Ticket ticket;
  initialiseTicket(&ticket);
  writeDownNumber(&ticket,2);
  writeDownNumber(&ticket,17);
  writeDownNumber(&ticket,25);

  int8_t numberToDelete = 17;
  deleteNumberFromTicket(&ticket, numberToDelete);

  int i;
  bool exists = false;
  for(i = 0; i < ticket.currentNumber; i++)
  {
    if(ticket.numbers[i] == numberToDelete)
    {
      exists = true;
      break;
    }
  }

  TEST_ASSERT_TRUE(false == exists);
}

TEST(LogicDeleteNumber, IsCurrentNumberDecremented)
{
  Ticket ticket;
  initialiseTicket(&ticket);
  writeDownNumber(&ticket,15);
  writeDownNumber(&ticket,18);

  int8_t numberToDelete = 15;
  deleteNumberFromTicket(&ticket, numberToDelete);

  TEST_ASSERT_EQUAL_INT8(1, ticket.currentNumber);
}
