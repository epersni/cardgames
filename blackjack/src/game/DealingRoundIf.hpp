#ifndef CARDGAMES_BLACKJACK_GAME_DEALING_ROUND_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_DEALING_ROUND_IF_HPP

#include "CardReceiverIf.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct DealingRoundIf
{
  using Ptr = std::shared_ptr<DealingRoundIf>;
  virtual void JoinNextDealingRound(CardReceiverIf::Ptr cardReceiver) = 0;
};

}

#endif

