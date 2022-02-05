#ifndef CARDGAMES_BLACKJACK_GAME_GAME_STATE_RECEIVER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_STATE_RECEIVER_IF_HPP

#include "GameState.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct GameStateReceiverIf
{
  using Ptr = std::shared_ptr<GameStateReceiverIf>;
  virtual void ReceiveGameState(const GameState newState) = 0;
};

}

#endif


