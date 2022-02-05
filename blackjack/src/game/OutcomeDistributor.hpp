#ifndef CARDGAMES_BLACKJACK_GAME_OUTCOME_DISTRIBUTOR_HPP
#define CARDGAMES_BLACKJACK_GAME_OUTCOME_DISTRIBUTOR_HPP

#include "OutcomeDistributorIf.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class OutcomeDistributor : public OutcomeDistributorIf
{
public:
  void Subscribe(const OutcomeReceiverIf::Ptr& receiver);
  void ReceiveOutcomes(OutcomeReceiverIf::PlayerOutcomeMap&& playerOutcomes);//TODO: not really good that this function is public, basically it is only Game.cpp that shall be allowed to call this
  
private:
  std::vector<OutcomeReceiverIf::Ptr> mReceivers;
};

}

#endif


