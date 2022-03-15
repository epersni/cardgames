#ifndef CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_HPP

#include "PlayersQueueIf.hpp"
#include "PlayersQueueInjectionIf.hpp"

#include <memory>
#include <vector>

namespace cardgames::blackjack::game{

class PlayersQueue
  : public PlayersQueueIf
  , public PlayersQueueInjectionIf
{
public:
  bool AnyInQueue() const override;
  PlayableHandIf::Ptr PopNextInQueue() override;
  void Inject(const PlayableHandIf::Ptr& newHand) override;
  void InjectAfter(const PlayableHandIf::Ptr& newHand, 
                   const PlayableHandIf::Ptr& afterThisHand) override;
private:
  std::vector<PlayableHandIf::Ptr> mHands; 
};

}

#endif


