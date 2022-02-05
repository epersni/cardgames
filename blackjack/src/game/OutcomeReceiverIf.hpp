#ifndef CARDGAMES_BLACKJACK_GAME_OUTCOME_RECEIVER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_OUTCOME_RECEIVER_IF_HPP

#include "Outcome.hpp"
#include "PlayableHandIf.hpp"

#include <map>
#include <memory>

namespace cardgames::blackjack::game{

struct OutcomeReceiverIf
{
  using Ptr = std::shared_ptr<OutcomeReceiverIf>;
  using PlayerOutcomeMap = std::map<PlayableHandIf::Ptr, Outcome>;
  virtual void ReceiveOutcomes(const PlayerOutcomeMap& playerOutcomes) = 0;
};

}

#endif



