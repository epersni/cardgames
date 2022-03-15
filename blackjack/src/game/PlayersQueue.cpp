#include "PlayersQueue.hpp"

#include <algorithm>

namespace cardgames::blackjack::game{

bool PlayersQueue::AnyInQueue() const
{
  return !mHands.empty();
}

PlayableHandIf::Ptr PlayersQueue::PopNextInQueue()
{
  auto head = mHands.front();
  mHands.erase(mHands.begin());
  return head;
}

void PlayersQueue::Inject(const PlayableHandIf::Ptr& newHand)
{
  mHands.emplace_back(newHand);
}


void PlayersQueue::InjectAfter(const PlayableHandIf::Ptr& newHand,
                               const PlayableHandIf::Ptr& afterThisHand)
{
  const auto it = std::find(mHands.begin(), mHands.end(), afterThisHand);
  mHands.insert(it+1, newHand);
}

}
