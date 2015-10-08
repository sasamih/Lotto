#include "../../unity/unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(LogicInitialiseTicket);
  RUN_TEST_GROUP(LogicWriteDownNumber);
  RUN_TEST_GROUP(LogicDeleteNumber);
}

int main(int argc, char* argv[])
{
  return UnityMain(argc,argv,RunAllTests);
}
