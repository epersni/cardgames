#include "OutcomeDistributor.hpp"

namespace cardgames::blackjack::game{

void OutcomeDistributor::Subscribe(const OutcomeReceiverIf::Ptr& receiver)
{
  mReceivers.push_back(receiver);
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
