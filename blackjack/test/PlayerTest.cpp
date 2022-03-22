#include "Player.hpp"
#include "GameStatePublisherIf.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct PlayerTest
{
  PlayerTest()
 //   : gameStateDistributor{
 //       MockPtr(GameStateDistributorIf, mockedGameStateDistributor)}
 //   , player(gameStateDistributor)
  {
  //  Fake(Method(mockedGameStateDistributor, Subscribe));
  }
 // Mock<GameStateDistributorIf> mockedGameStateDistributor; 
 // GameStateDistributorIf::Ptr gameStateDistributor;
 // Player player;
};

TEST_CASE_METHOD(
    PlayerTest,
    "Player subscribes to game states",
    "player")
{
  //Verify(Method(mockedGameStateDistributor, Subscribe)).Once();
}

TEST_CASE_METHOD(
    PlayerTest,
    "On AcceptingBets, Player enables the betting controls",
    "player")
{

  //CHECK(true);
}

