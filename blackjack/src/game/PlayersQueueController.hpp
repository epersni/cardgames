#ifndef CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_CONTROLLER_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYERS_QUEUE_CONTROLLER_HPP

#include "GameStateReceiverIf.hpp"
#include "PlayersQueueControllerIf.hpp"
#include "PlayersQueueIf.hpp"
#include "GameStateDistributorIf.hpp"

#include <memory>
#include <vector>

namespace cardgames::blackjack::game{

class PlayersQueueController
  : public PlayersQueueIf
  , public PlayersQueueControllerIf
  , public BetListener //To know when a Terminal wants to join the game
{
public:
  bool AnyInQueue() const override;
  PlayableHandIf::Ptr PopNextInQueue() override;
  void PushBack(const PlayableHandIf::Ptr& newHand) override;
  void InjectAfter(const PlayableHandIf::Ptr& afterThisHand, 
                   const cards::Card card) override;
private:
  std::vector<PlayingUserHand> mHands; 
};

}

#endif


