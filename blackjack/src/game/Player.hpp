#ifndef CARDGAMES_BLACKJACK_GAME_PLAYER_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYER_HPP

#include "BettingControlsIf.hpp"
#include "CardProviderIf.hpp"
#include "DealingRoundIf.hpp"
#include "GameStatePublisherIf.hpp"
#include "HandControlEnablerIf.hpp"
#include "PlayerIf.hpp"
#include "PlayersQueueInjectorIf.hpp"
#include "PlayingControlsIf.hpp"
#include "PlayingUserHand.hpp"
#include "TimerProviderIf.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class Player
  : public HandControlEnablerIf
  , public PlayerIf
  , public std::enable_shared_from_this<Player>
{
public:
  Player(const GameStatePublisherIf::Ptr& gameStatePublisher,
         const PlayersQueueInjectorIf::Ptr& queueInjector,
         const BettingControlsIf::Ptr& bettingControls,
         const PlayingControlsIf::Ptr& playingControls,
         const DealingRoundIf::Ptr& dealingRound,
         const CardProviderIf::Ptr& cardProvider,
         const TimerProviderIf::Ptr& timerProvider);

  std::vector<PlayableHandIf::Ptr> GetHands() const override;

private:
  const GameStatePublisherIf::Ptr mGameStatePublisher;
  const PlayersQueueInjectorIf::Ptr mQueueInjector;
  const BettingControlsIf::Ptr mBettingControls;
  const PlayingControlsIf::Ptr mPlayingControls;
  const DealingRoundIf::Ptr mDealingRound;
  const CardProviderIf::Ptr mCardProvider;
  const TimerProviderIf::Ptr mTimerProvider;
  std::vector<std::shared_ptr<PlayingUserHand>> mHands;

  void onGameStateChange(GameState newGameState);
  void EnableActions(const AllowedActions& actions) override;
};

}

#endif

