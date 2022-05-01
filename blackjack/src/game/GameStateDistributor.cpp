#include "GameStateDistributor.hpp"
#include "Logging.hpp"

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
  for(auto cb : mCallbacks)
  {
    cb(newState);
  }
}

}

