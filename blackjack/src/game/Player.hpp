#ifndef CARDGAMES_BLACKJACK_GAME_PLAYER_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYER_HPP

#include "BettingControlsIf.hpp"
#include "CardProviderIf.hpp"
#include "GameStatePublisherIf.hpp"
#include "HandControlEnablerIf.hpp"
#include "PlayersQueueInjectorIf.hpp"
#include "PlayingControlsIf.hpp"
#include "PlayingUserHand.hpp"
#include "TimerProviderIf.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class Player
  : public HandControlEnablerIf
  , std::enable_shared_from_this<Player>
{
public:
  Player(const GameStatePublisherIf::Ptr& gameStatePublisher,
         const PlayersQueueInjectorIf::Ptr& queueInjector,
         const BettingControlsIf::Ptr& bettingControls,
         const PlayingControlsIf::Ptr& playingControls,
         const CardProviderIf::Ptr& cardProvider,
         const TimerProviderIf::Ptr& timerProvider);

  //TODO: 
  //We want a public method to get the hands a Player has at the moment
  //but we do not want that public method to give access to change that hand. 
  //A new interface for ReadOnlyHandIf, sort of...
   


private:
  const GameStatePublisherIf::Ptr& mGameStatePublisher;
  const PlayersQueueInjectorIf::Ptr& mQueueInjector;
  const BettingControlsIf::Ptr& mBettingControls;
  const PlayingControlsIf::Ptr& mPlayingControls;
  const CardProviderIf::Ptr& mCardProvider;
  const TimerProviderIf::Ptr& mTimerProvider;
  std::vector<std::shared_ptr<PlayingUserHand>> mHands;

  void onGameStateChange(GameState newGameState);
  void EnableActions(const AllowedActions& actions) override;
};

}

#endif

