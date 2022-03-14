#include "Game.hpp"

namespace cardgames::blackjack::game{

Game::Game(const PlayersQueueIf::Ptr playersQueue,
           const std::shared_ptr<PlayableHandIf>& dealer,
           const std::shared_ptr<TimerProviderIf>& timerProvider,
           const std::shared_ptr<OutcomeFactoryIf>& outcomeProvider,
           const std::shared_ptr<OutcomeDistributorIf>& outcomeDistributor,
           const std::shared_ptr<GameStateDistributorIf>& gameStateDistributor,
           const std::shared_ptr<CardDealerIf>& cardDealer)
  : mPlayersQueue(playersQueue)
  , mDealer(dealer)
  , mTimerProvider(timerProvider)
  , mOutcomeFactory(outcomeProvider)
  , mOutcomeDistributor(outcomeDistributor)
  , mGameStateDistributor(gameStateDistributor)
  , mCardDealer(cardDealer)
{
}

void Game::StartGame()
{
  mGameStateDistributor->ReceiveGameState(GameState::AcceptingBets);
  mTimerProvider->
    AcceptingBetsTimerCb([this](){ this->onAcceptingBetsTimedOut(); });
}

void Game::onAcceptingBetsTimedOut()
{
  mGameStateDistributor->ReceiveGameState(GameState::DealingCards);
  mCardDealer->DealCards([this]() { this->onCardsDealt(); });
}

void Game::onCardsDealt()
{
  mGameStateDistributor->ReceiveGameState(GameState::PlayersPlaying);
  onPlayerDonePlaying();
}

void Game::onPlayerDonePlaying()
{
  if(mPlayersQueue->AnyInQueue())
  {
    auto hand = mPlayersQueue->PopNextInQueue();
    mPlayedHands.push_back(hand);
    hand->Play([this](){ this->onPlayerDonePlaying(); });
  }
  else
  {
    mGameStateDistributor->ReceiveGameState(GameState::DealerPlaying);
    mDealer->Play([this](){ this->onDealerDonePlaying(); });
  }
}

void Game::onDealerDonePlaying()
{
  mGameStateDistributor->ReceiveGameState(GameState::Outcome);
  std::map<std::shared_ptr<PlayableHandIf>, Outcome> playerOutcomeMap;
  for(auto p : mPlayedHands)
  {
    playerOutcomeMap[p] = mOutcomeFactory->CreateOutcome(p, mDealer);
  }
  mOutcomeDistributor->ReceiveOutcomes(std::move(playerOutcomeMap));
}

}