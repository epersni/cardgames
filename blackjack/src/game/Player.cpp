#include "Player.hpp"

#include <algorithm>

namespace cardgames::blackjack::game{


Player::Player(const GameStatePublisherIf::Ptr& gameStatePublisher,
               const PlayersQueueInjectorIf::Ptr& queueInjector,
               const BettingControlsIf::Ptr& bettingControls,
               const PlayingControlsIf::Ptr& playingControls,
               const CardProviderIf::Ptr& cardProvider,
               const TimerProviderIf::Ptr& timerProvider)
  : mGameStatePublisher(gameStatePublisher)
  , mQueueInjector(queueInjector)
  , mBettingControls(bettingControls)
  , mPlayingControls(playingControls)
  , mCardProvider(cardProvider)
  , mTimerProvider(timerProvider)
{
  mGameStatePublisher->Subscribe(
      [this](GameState newState){ onGameStateChange(newState); });
}

void Player::EnableActions(const AllowedActions& actions)
{
  mPlayingControls->DisableAll();

  auto hand = std::find_if(begin(mHands),
                           end(mHands),
                           [](auto h){ return h->IsPlaying(); });

  for(auto action : actions)
  {
    switch(action)
    {
      case HandAction::Stand:
        mPlayingControls->OnStand([hand](){ (*hand)->Stand(); });
        break;
      case HandAction::Hit:
        mPlayingControls->OnHit([hand](){ (*hand)->Hit(); });
        break;
      case HandAction::Double:
        mPlayingControls->OnDouble([hand](){ (*hand)->Double(); });
        break;
      case HandAction::Split:
        mPlayingControls->OnDouble([hand](){ /* TODO fix this*/ });
        break;
    };
  }
}

void Player::onGameStateChange(GameState newGameState)
{
  mBettingControls->DisableAll();
  mPlayingControls->DisableAll();
  
  switch(newGameState)
  {
    case GameState::AcceptingBets:
      mBettingControls->OnPlaceBet(
          [this](auto amount)
          {
            (void)amount;
            const auto newHand = 
                std::make_shared<PlayingUserHand>(mCardProvider, 
                                                  mTimerProvider, 
                                                  shared_from_this());
            mHands.push_back(newHand);
            mQueueInjector->Inject(newHand);
          });
      break;
    case GameState::PlayersPlaying:
      break;
    case GameState::Outcome:
      //Calculate wins
      //mHands.clear();
      break;
    case GameState::DealingCards:
    case GameState::DealerPlaying:
      break;
  };
}

}
