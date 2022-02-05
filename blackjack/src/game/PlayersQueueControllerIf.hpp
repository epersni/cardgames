#ifndef CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_CONTROLLER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_CONTROLLER_IF_HPP

#include "PlayableHandIf.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct PlayersQueueControllerIf
{
  using Ptr = std::shared_ptr<PlayersQueueControllerIf>;
  virtual void PushBack(const PlayableHandIf::Ptr& newHand) = 0;
  virtual void InjectAfter(const PlayableHandIf::Ptr& afterThisHand, 
                           const cards::Card card) = 0;
};

}

#endif

