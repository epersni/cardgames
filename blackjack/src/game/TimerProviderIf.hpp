#ifndef CARDGAMES_BLACKJACK_GAME_TIMER_PROVIDER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_TIMER_PROVIDER_IF_HPP

#include <functional>
#include <memory>

namespace cardgames::blackjack::game{

struct TimerProviderIf
{
  using Ptr = std::shared_ptr<TimerProviderIf>;
  using TimeExpiredCb = std::function<void()>;
  virtual void AcceptingBetsTimerCb(TimeExpiredCb callback) = 0;
  virtual void DealerDecisionTimerCb(TimeExpiredCb callback) = 0;
  virtual void PlayingUserHandTimerCb(TimeExpiredCb callback) = 0;
};

}

#endif


