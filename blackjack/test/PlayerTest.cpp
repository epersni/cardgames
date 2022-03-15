#include "Player.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct PlayerTest
{
  PlayerTest()
  {
  }
  Player player;
};

TEST_CASE_METHOD(
    PlayerTest,
    "Creating a Player",
    "dealing")
{
  CHECK(true);
}

