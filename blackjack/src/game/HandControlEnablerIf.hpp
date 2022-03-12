#ifndef CARDGAMES_BLACKJACK_GAME_HAND_CONTROL_ENABLER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_HAND_CONTROL_ENABLER_IF_HPP

#include "HandAction.hpp"

#include <memory>
#include <set>

namespace cardgames::blackjack::game{

struct HandControlEnablerIf
{
  using Ptr = std::shared_ptr<HandControlEnablerIf>;
  using AllowedActions = std::set<HandAction>;
  virtual void EnableActions(const AllowedActions& actions) = 0;
};

}

#endif



