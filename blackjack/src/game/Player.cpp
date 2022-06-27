#include "Player.hpp"
#include "Logging.hpp"

#include <algorithm>

namespace cardgames::blackjack::game{
namespace
{
  auto log = logging::Logger::createLogger("Player");
}

Player::Player(const GameStatePublisherIf::Ptr& gameStatePublisher,
               const PlayersQueueInjectorIf::Ptr& queueInjector,
               const BettingControlsIf::Ptr& bettingControls,
               const PlayingControlsIf::Ptr& playingControls,
               const DealingRoundIf::Ptr& dealingRound,
               const CardProviderIf::Ptr& cardProvider,
               const TimerProviderIf::Ptr& timerProvider)
  : mGameStatePublisher(gameStatePublisher)
  , mQueueInjector(queueInjector)
  , mBettingControls(bettingControls)
  , mPlayingControls(playingControls)
  , mDealingRound(dealingRound)
  , mCardProvider(cardProvider)
  , mTimerProvider(timerProvider)
{
  log.info("Creating a player");
  mGameStatePublisher->Subscribe(
      [this](GameState newState){ onGameStateChange(newState); });
}

std::vector<PlayableHandIf::Ptr> Player::GetHands() const
{
  std::vector<PlayableHandIf::Ptr> hands;

  for(auto hand : mHands)
  {
    hands.push_back(hand);
  }

  return hands;
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
  log.debug("Game state received"); //TODO: log gameState
  mBettingControls->DisableAll(); // TODO this does not exist..... START HERE 
  
  switch(newGameState)
  {
    case GameState::AcceptingBets:
      mBettingControls->OnPlaceBet(
          [this](auto amount)
          {
            log.info("Bet is placed, creating new hand and adding to players queue");
            (void)amount;
            const auto newHand = 
                std::make_shared<PlayingUserHand>(mCardProvider, 
                                                  mTimerProvider, 
                                                  shared_from_this());
            mHands.push_back(newHand);
            mQueueInjector->Inject(newHand);
            mDealingRound->JoinNextDealingRound(newHand);
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
