#include "Game.hpp"

namespace cardgames::blackjack::game{

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
  mGameStateReceiver->ReceiveGameState(GameState::AcceptingBets);
  mTimerProvider->
    AcceptingBetsTimerCb([this](){ this->onAcceptingBetsTimedOut(); });
}

void Game::onAcceptingBetsTimedOut()
{
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
    auto hand = mPlayersQueue->PopNextInQueue();
    mPlayedHands.push_back(hand);
    hand->Play([this](){ this->onPlayerDonePlaying(); });
  }
  else
  {
    mGameStateReceiver->ReceiveGameState(GameState::DealerPlaying);
    mDealer->Play([this](){ this->onDealerDonePlaying(); });
  }
}

void Game::onDealerDonePlaying()
{
  mGameStateReceiver->ReceiveGameState(GameState::Outcome);
  std::map<std::shared_ptr<PlayableHandIf>, Outcome> playerOutcomeMap;
  for(auto p : mPlayedHands)
  {
    playerOutcomeMap[p] = mOutcomeFactory->CreateOutcome(p, mDealer);
  }
  mOutcomeDistributor->ReceiveOutcomes(std::move(playerOutcomeMap));
}

}
