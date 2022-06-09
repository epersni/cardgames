#include "Game.hpp"
#include "Logging.hpp"

namespace cardgames::blackjack::game{
namespace
{
  auto log = logging::Logger::createLogger("Game");
}

Game::Game(const PlayersQueueIf::Ptr playersQueue,
           const std::shared_ptr<PlayableHandIf>& dealer,
           const std::shared_ptr<TimerProviderIf>& timerProvider,
           const std::shared_ptr<OutcomeFactoryIf>& outcomeProvider,
           const std::shared_ptr<OutcomeDistributorIf>& outcomeDistributor,
           const std::shared_ptr<GameStateReceiverIf>& gameStateReceiver,
           const std::shared_ptr<CardDealerIf>& cardDealer)
  : mPlayersQueue(playersQueue)
  , mDealer(dealer)
  , mTimerProvider(timerProvider)
  , mOutcomeFactory(outcomeProvider)
  , mOutcomeDistributor(outcomeDistributor)
  , mGameStateReceiver(gameStateReceiver)
  , mCardDealer(cardDealer)
{
}

void Game::StartGame()
{
  log.info("Starting a new game");
  mGameStateReceiver->ReceiveGameState(GameState::AcceptingBets);
  mTimerProvider->
    AcceptingBetsTimerCb([this](){ this->onAcceptingBetsTimedOut(); });
}

bool Game::IsGameOver() const
{
  return gameOver;
}

void Game::onAcceptingBetsTimedOut()
{
  log.info("No more bets allowed, instruct dealer to deal cards");
  mGameStateReceiver->ReceiveGameState(GameState::DealingCards);
  mCardDealer->DealCards([this]() { this->onCardsDealt(); });
}

void Game::onCardsDealt()
{
  mGameStateReceiver->ReceiveGameState(GameState::PlayersPlaying);
  onPlayerDonePlaying();
}

void Game::onPlayerDonePlaying()
{
  if(mPlayersQueue->AnyInQueue())
  {
    log.info("Let next playable hand in queue play");
    auto hand = mPlayersQueue->PopNextInQueue();
    mPlayedHands.push_back(hand);
    hand->Play([this](){ this->onPlayerDonePlaying(); });
  }
  else
  {
    log.info("Let dealer play");
    mGameStateReceiver->ReceiveGameState(GameState::DealerPlaying);
    mDealer->Play([this](){ this->onDealerDonePlaying(); });
  }
}

void Game::onDealerDonePlaying()
{
  log.info("Dealer have played, now game is over");
  gameOver = true;
  mGameStateReceiver->ReceiveGameState(GameState::Outcome);
  std::map<std::shared_ptr<PlayableHandIf>, Outcome> playerOutcomeMap;
  for(auto p : mPlayedHands)
  {
    playerOutcomeMap[p] = mOutcomeFactory->CreateOutcome(p, mDealer);
  }
  mOutcomeDistributor->ReceiveOutcomes(std::move(playerOutcomeMap));
}

}
