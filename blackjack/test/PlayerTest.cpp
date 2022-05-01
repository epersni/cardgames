#include "BettingControlsIf.hpp"
#include "GameStatePublisherIf.hpp"
#include "Player.hpp"
#include "PlayersQueueInjectorIf.hpp"
#include "PlayingControlsIf.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

  //TODO: complete this test suite with tests
struct PlayerTest
{
  PlayerTest()
    : gameStatePublisher{MockPtr(GameStatePublisherIf, mockedGameStatePublisher)}
    , playersQueueInjector{MockPtr(PlayersQueueInjectorIf, mockedPlayersQueueInjector)}
    , bettingControls{MockPtr(BettingControlsIf, mockedBettingControls)}
    , playingControls{MockPtr(PlayingControlsIf, mockedPlayingControls)}
  {
    Fake(Method(mockedBettingControls, OnPlaceBet));
    Fake(Method(mockedBettingControls, DisableAll));
    //Fake(Method(mockedPlayingControls, Enable));
    Fake(Method(mockedPlayingControls, DisableAll));

    When(
      Method(mockedGameStatePublisher, Subscribe))
        .Do([this](auto cb){ changeStateCb = cb; });

    player = std::make_unique<Player>(gameStatePublisher,
                                      playersQueueInjector,
                                      bettingControls,
                                      playingControls,
                                      nullptr, nullptr);
  }
  Mock<GameStatePublisherIf> mockedGameStatePublisher;
  std::shared_ptr<GameStatePublisherIf> gameStatePublisher;
  Mock<PlayersQueueInjectorIf> mockedPlayersQueueInjector;
  std::shared_ptr<PlayersQueueInjectorIf> playersQueueInjector;
  Mock<BettingControlsIf> mockedBettingControls;
  std::shared_ptr<BettingControlsIf> bettingControls;
  Mock<PlayingControlsIf> mockedPlayingControls;
  std::shared_ptr<PlayingControlsIf> playingControls;
  GameStatePublisherIf::GameStateChangeCb changeStateCb;
  std::unique_ptr<Player> player;
};

TEST_CASE_METHOD(
    PlayerTest,
    "Player subscribes to game states",
    "player")
{
  Verify(Method(mockedGameStatePublisher, Subscribe));
}

TEST_CASE_METHOD(
    PlayerTest,
    "On AcceptingBets enable betting controls",
    "player")
{
  changeStateCb(GameState::AcceptingBets);
  Verify(
      Method(mockedBettingControls, DisableAll),
      Method(mockedBettingControls, OnPlaceBet));
}

TEST_CASE_METHOD(
    PlayerTest,
    "On PlayersPlaying enable playing controls",
    "player")
{
 // changeStateCb(GameState::PlayersPlaying);
 // Verify(
 //     Method(mockedPlayingControls, DisableAll),
 //     Method(mockedPlayingControls, Enable));
}

