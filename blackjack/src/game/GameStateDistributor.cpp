#include "GameStateDistributor.hpp"
#include "Logging.hpp"
#include <iostream> //TODO;

namespace cardgames::blackjack::game{
namespace
{
  auto log = logging::Logger::createLogger("GameStateDistributor");
}

void GameStateDistributor::Subscribe(GameStateChangeCb cb)
{
  log.trace("Adding subscriber");
  mCallbacks.push_back(cb);
}

void GameStateDistributor::ReceiveGameState(const GameState newState)
{
  log.debug("Distributing new game state"); // TODO: log newState
  for(auto cb : mCallbacks)
  {
    cb(newState);
  }
}

}

