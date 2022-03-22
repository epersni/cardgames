#include "Game.hpp"
#include "GameState.hpp"
#include "GameStateReceiverIf.hpp"
#include "OutcomeFactoryIf.hpp"
#include "PlayableHandIf.hpp"
#include "TimerProviderIf.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct MultiPlayerTest
{
  MultiPlayerTest()
    : player{MockPtr(PlayableHandIf, mockedPlayer)}
    , dealer{MockPtr(PlayableHandIf, mockedDealer)}
    , timerProvider{MockPtr(TimerProviderIf, mockedTimerProvider)}
    , outcomeProvider{MockPtr(OutcomeFactoryIf, mockedOutcomeProvider)}
    , outcomeDistributor{MockPtr(OutcomeDistributorIf, mockedOutcomeDistributor)}
    , gameStateReceiver{MockPtr(GameStateReceiverIf, mockedGameStateReceiver)}
    , cardDealer{MockPtr(CardDealerIf, mockedCardDealer)}
    , playersQueue{MockPtr(PlayersQueueIf, mockedPlayersQueue)}
    , game(playersQueue,
           dealer,
           timerProvider,
           outcomeProvider,
           outcomeDistributor,
           gameStateReceiver,
           cardDealer)
  {
    Fake(Method(mockedPlayer,Play)); 
    Fake(Method(mockedGameStateReceiver, ReceiveGameState));
    Fake(Method(mockedOutcomeProvider, CreateOutcome));
    Fake(Method(mockedOutcomeDistributor, ReceiveOutcomes));
    When(Method(mockedTimerProvider, AcceptingBetsTimerCb)).AlwaysDo(
        [](TimerProviderIf::TimeExpiredCb cb){ cb(); });
    When(Method(mockedCardDealer, DealCards)).AlwaysDo(
        [](CardDealerIf::CardsDealtCb cb){ cb(); });
    When(Method(mockedPlayersQueue, PopNextInQueue))
      .AlwaysReturn(player);
    When(Method(mockedPlayersQueue, AnyInQueue)).Return(4_Times(true), 100_Times(false));
  }
  
  Mock<PlayableHandIf> mockedPlayer;
  PlayableHandIf::Ptr player;
  Mock<PlayableHandIf> mockedDealer;
  std::shared_ptr<PlayableHandIf> dealer;
  Mock<TimerProviderIf> mockedTimerProvider;
  std::shared_ptr<TimerProviderIf> timerProvider;
  Mock<OutcomeFactoryIf> mockedOutcomeProvider;
  std::shared_ptr<OutcomeFactoryIf> outcomeProvider;
  Mock<OutcomeDistributorIf> mockedOutcomeDistributor;
  std::shared_ptr<OutcomeDistributorIf> outcomeDistributor;
  Mock<GameStateReceiverIf> mockedGameStateReceiver;
  std::shared_ptr<GameStateReceiverIf> gameStateReceiver;
  Mock<CardDealerIf> mockedCardDealer;
  std::shared_ptr<CardDealerIf> cardDealer;
  Mock<PlayersQueueIf> mockedPlayersQueue;
  PlayersQueueIf::Ptr playersQueue;
  Game game;
};

TEST_CASE_METHOD(
    MultiPlayerTest,
    "On StartGame and players in queue, AcceptingBets is sent to gameStateReceiver", 
    "[game]")
{
  game.StartGame();
  Verify(Method(mockedGameStateReceiver, ReceiveGameState)
      .Using(GameState::AcceptingBets)).Once();
}

TEST_CASE_METHOD(
    MultiPlayerTest,
    "On game started, use timer to wait time before leaving AcceptingBets", 
    "[game]")
{
  game.StartGame();
  Verify(Method(mockedTimerProvider, AcceptingBetsTimerCb)); 
}

TEST_CASE_METHOD(
  MultiPlayerTest,
  "After AcceptingBets, request dealer to deal cards", 
  "[game]")
{
  game.StartGame();
  Verify(
      Method(mockedGameStateReceiver, ReceiveGameState)
        .Using(GameState::AcceptingBets),
      Method(mockedGameStateReceiver, ReceiveGameState)
        .Using(GameState::DealingCards),
      Method(mockedCardDealer, DealCards)).Exactly(Once);
}

TEST_CASE_METHOD(
    MultiPlayerTest,
    "After AcceptingBets, state is DealingCards", 
    "[game]")
{
  game.StartGame();
  Verify(
      Method(mockedGameStateReceiver, ReceiveGameState)
        .Using(GameState::AcceptingBets),
      Method(mockedGameStateReceiver, ReceiveGameState)
        .Using(GameState::DealingCards))
    .Exactly(Once);
}


TEST_CASE_METHOD(
    MultiPlayerTest,
    "On PlayersPlaying, state is sent to GameStateDistributor", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedGameStateReceiver, ReceiveGameState)
      .Using(GameState::PlayersPlaying)).Once();
}

TEST_CASE_METHOD(
    MultiPlayerTest, 
    "Each players gets to play", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedPlayersQueue, PopNextInQueue),
         Method(mockedPlayer, Play), 
         Method(mockedPlayersQueue, PopNextInQueue),
         Method(mockedPlayer, Play),
         Method(mockedPlayersQueue, PopNextInQueue),
         Method(mockedPlayer, Play),
         Method(mockedPlayersQueue, PopNextInQueue),
         Method(mockedPlayer, Play)).Once();
}

TEST_CASE_METHOD(
    MultiPlayerTest, 
    "When all players have played, dealer gets to play", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedPlayer, Play), 
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedDealer, Play)).Once();
}

TEST_CASE_METHOD(
    MultiPlayerTest, 
    "On DealerPlaying, state is sent to GameStateDistributor", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedGameStateReceiver, ReceiveGameState)
         .Using(GameState::PlayersPlaying),
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedGameStateReceiver, ReceiveGameState)
         .Using(GameState::DealerPlaying),
         Method(mockedDealer, Play)).Once();
}

TEST_CASE_METHOD(
    MultiPlayerTest, 
    "On Outcome, state is sent to GameStateDistributor", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedPlayer, Play),
         Method(mockedDealer, Play),
         Method(mockedGameStateReceiver, ReceiveGameState)
         .Using(GameState::Outcome)).Once();
}

TEST_CASE_METHOD(
    MultiPlayerTest, 
    "When game is done, create outcome for each player", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedOutcomeProvider, CreateOutcome)).Exactly(4_Times);
}

TEST_CASE_METHOD(
    MultiPlayerTest, 
    "When game is done, send outcomes to OutcomeDistributor", 
    "[game]")
{
  When(Method(mockedPlayer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  When(Method(mockedDealer,Play)).Do([](PlayableHandIf::DonePlayingCb cb){ cb(); });
  game.StartGame();
  Verify(Method(mockedOutcomeDistributor, ReceiveOutcomes)).Once();
}

