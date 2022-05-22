#ifndef CARDGAMES_BLACKJACK_GAME_GAME_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_HPP

#include "CardDealerIf.hpp"
#include "GameStateReceiverIf.hpp"
#include "OutcomeDistributorIf.hpp"
#include "OutcomeFactoryIf.hpp"
#include "PlayableHandIf.hpp"
#include "PlayersQueueIf.hpp"
#include "TimerProviderIf.hpp"

#include <memory>
#include <queue>

namespace cardgames::blackjack::game{

class Game
{
public:
  Game(const PlayersQueueIf::Ptr playersQueue,
       const std::shared_ptr<PlayableHandIf>& dealer,
       const std::shared_ptr<TimerProviderIf>& timerProvider,
       const std::shared_ptr<OutcomeFactoryIf>& outcomeProvider,
       const std::shared_ptr<OutcomeDistributorIf>& outcomeDistributor,
       const std::shared_ptr<GameStateReceiverIf>& gameStateDistributor,
       const std::shared_ptr<CardDealerIf>& cardDealer);
  
  void StartGame();
  bool IsGameOver() const;

private:
  const PlayersQueueIf::Ptr mPlayersQueue;
  const PlayableHandIf::Ptr mDealer;
  const std::shared_ptr<TimerProviderIf> mTimerProvider;
  const std::shared_ptr<OutcomeFactoryIf> mOutcomeFactory;
  const std::shared_ptr<OutcomeDistributorIf> mOutcomeDistributor;
  const std::shared_ptr<GameStateReceiverIf> mGameStateReceiver;
  const std::shared_ptr<CardDealerIf> mCardDealer;
  GameState mState{GameState::AcceptingBets};
  std::vector<PlayableHandIf::Ptr> mPlayedHands;
  bool gameOver{false};
  
  void onAcceptingBetsTimedOut();
  void onCardsDealt();
  void onPlayerDonePlaying();
  void onDealerDonePlaying();
};

}

#endif
