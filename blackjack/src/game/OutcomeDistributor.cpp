#include "OutcomeDistributor.hpp"


//TODO: These kind of distributors could be templatized

namespace cardgames::blackjack::game{

void OutcomeDistributor::Subscribe(const OutcomeReceiverIf::Ptr& receiver)
{
  mReceivers.insert(receiver);
}

void OutcomeDistributor::ReceiveOutcomes(
    OutcomeReceiverIf::PlayerOutcomeMap&& playerOutcomes)
{
  for(auto& receiver : mReceivers)
  {
    receiver->ReceiveOutcomes(playerOutcomes);
  }
}

}
