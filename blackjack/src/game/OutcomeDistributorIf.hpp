#ifndef CARDGAMES_BLACKJACK_GAME_OUTCOME_DISTRIBUTOR_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_OUTCOME_DISTRIBUTOR_IF_HPP

#include "Outcome.hpp"
#include "OutcomeReceiverIf.hpp"

namespace cardgames::blackjack::game{

struct OutcomeDistributorIf
{
  virtual void Subscribe(const OutcomeReceiverIf::Ptr& receiver) = 0;
  virtual void ReceiveOutcomes(OutcomeReceiverIf::PlayerOutcomeMap&& playerOutcomes) = 0;
};

}

#endif
