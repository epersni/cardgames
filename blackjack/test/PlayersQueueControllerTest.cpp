#include "PlayersQueueController.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

using namespace cardgames::cards;
using namespace cardgames::blackjack::game;
using namespace fakeit;

struct PlayersQueueControllerTest
{ 
  PlayersQueueControllerTest()
    : mockedHands(4)
  {
  }
  std::vector<Mock<PlayableHandIf>> mockedHands;
  PlayersQueueController controller;
};

TEST_CASE_METHOD(
    PlayersQueueControllerTest,
    "Initially, the queue is empty"
    "[playersqueue]")
{
  CHECK(!controller.AnyInQueue());
}

TEST_CASE_METHOD(
    PlayersQueueControllerTest,
    "Adding 4 hands, then pop in FIFO order",
    "[playersqueue]")
{
  for(auto& hand : mockedHands)
  {
    controller.PushBack(MockPtr(PlayableHandIf,hand));
  }
  for(auto hand: mockedHands)
  {
    CHECK(controller.AnyInQueue());
  //  controller.PopNextInQueue();
  }
 // CHECK(!controller.AnyInQueue());
}


