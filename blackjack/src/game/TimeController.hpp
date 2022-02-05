#ifndef CARDGAMES_BLACKJACK_GAME_TIME_CONTROLLER_HPP
#define CARDGAMES_BLACKJACK_GAME_TIME_CONTROLLER_HPP

#include "TimerProviderIf.hpp"

#include <cstdint>
#include <vector>

namespace cardgames::blackjack::game{

class TimeController : public TimerProviderIf
{
public:
  void IncrementGameTimeMs(uint32_t timeMs);
  void AcceptingBetsTimerCb(TimeExpiredCb callback) final;
  void DealerDecisionTimerCb(TimeExpiredCb callback) final;
private:
  struct TimerInfo
  {
    TimeExpiredCb callback;
    uint32_t timeLeft;
  };

  std::vector<TimerInfo> mTimers;
};

}

#endif



