#include "PlayersQueueController.hpp"

namespace cardgames::blackjack::game{

bool PlayersQueueController::AnyInQueue() const
{
  return mHands.empty();
}

PlayableHandIf::Ptr PlayersQueueController::PopNextInQueue()
{
  auto head = mHands.front();
  mHands.erase(mHands.begin());
  return head;
}

void PlayersQueueController::PushBack(const PlayableHandIf::Ptr& newHand)
{
}

void PlayersQueueController::InjectAfter(
    const PlayableHandIf::Ptr& afterThisHand,
    const cards::Card card)
{
}

}
