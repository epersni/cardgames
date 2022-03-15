#ifndef CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_INJECTION_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_INJECTION_IF_HPP

#include "PlayableHandIf.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct PlayersQueueInjectionIf
{
  virtual void Inject(const PlayableHandIf::Ptr& newHand) = 0;
  virtual void InjectAfter(const PlayableHandIf::Ptr& newHand, 
                           const PlayableHandIf::Ptr& afterThisHand) = 0;
};

}

#endif
