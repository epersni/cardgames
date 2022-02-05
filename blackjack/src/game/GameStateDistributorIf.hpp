#ifndef CARDGAMES_BLACKJACK_GAME_GAME_STATE_DISTRIBUTOR_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_STATE_DISTRIBUTOR_IF_HPP

#include "GameState.hpp"
#include "GameStateReceiverIf.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct GameStateDistributorIf
{
  using Ptr = std::shared_ptr<GameStateDistributorIf>;
  virtual void Subscribe(const GameStateReceiverIf::Ptr& receiver) = 0;
  virtual void ReceiveGameState(const GameState newState) = 0;
};

}

#endif

