#include "GameStateDistributor.hpp"

namespace cardgames::blackjack::game{

void GameStateDistributor::Subscribe(GameStateChangeCb cb)
{
  mCallbacks.push_back(cb);
}

void GameStateDistributor::ReceiveGameState(const GameState newState)
{
  for(auto cb : mCallbacks)
  {
    cb(newState);
  }
}

}

