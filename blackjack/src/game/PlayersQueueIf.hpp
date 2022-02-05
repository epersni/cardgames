#ifndef CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_IF_HPP

#include "PlayableHandIf.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct PlayersQueueIf
{
  using Ptr = std::shared_ptr<PlayersQueueIf>;
  virtual bool AnyInQueue() const = 0;
  virtual PlayableHandIf::Ptr PopNextInQueue() = 0;
};

}

#endif
