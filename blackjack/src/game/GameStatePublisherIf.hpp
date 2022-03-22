#ifndef CARDGAMES_BLACKJACK_GAME_GAME_STATE_PUBLISHER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_STATE_PUBLISHER_IF_HPP

#include "GameState.hpp"
#include "GameStateReceiverIf.hpp"

#include <memory>
#include <functional>

namespace cardgames::blackjack::game{

struct GameStatePublisherIf
{
  using Ptr = std::shared_ptr<GameStatePublisherIf>;
  using GameStateChangeCb = std::function<void(GameState)>;
  virtual void Subscribe(GameStateChangeCb cb) = 0;
  virtual void ReceiveGameState(const GameState newState) = 0;
};

}

#endif

