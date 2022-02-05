#include "GameStateDistributor.hpp"

namespace cardgames::blackjack::game{

void GameStateDistributor::Subscribe(const GameStateReceiverIf::Ptr& receiver)
{
  mReceivers.push_back(receiver);
}

void GameStateDistributor::ReceiveGameState(const GameState newState)
{
  for(auto receiver : mReceivers)
  {
    receiver->ReceiveGameState(newState);
  }
}

}

