#include "GameStateDistributor.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

TEST_CASE("Creating a GameStateDistributor", "GameStateDistributor")
{
  (void)GameStateDistributor();
}

TEST_CASE("Single subscriber", "GameStateDistributor")
{
  auto state = GENERATE(GameState::AcceptingBets, 
                        GameState::PlayersPlaying,
                        GameState::DealerPlaying, 
                        GameState::Outcome);
  GameStateDistributor distributor;
  bool called = false;
  distributor.Subscribe([&called](GameState newState){ called = true; });
  CHECK(!called);
  distributor.ReceiveGameState(state);
  CHECK(called);
}

