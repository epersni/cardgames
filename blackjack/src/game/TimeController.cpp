#include "TimeController.hpp"

#include "Logging.hpp"

#include <algorithm>

namespace cardgames::blackjack::game{
namespace{
  logging::Logger log = logging::Logger::createLogger("TimeController");
  const uint32_t ACCEPTING_BETS_TIME_MS = 4000;
  const uint32_t DEALER_DECISION_TIME_MS = 1000;
  const uint32_t PLAYING_USER_HAND_TIME_MS = 20000;
}

void TimeController::IncrementGameTimeMs(uint32_t timeMs)
{
  std::for_each(mTimersToBeJoined.begin(), mTimersToBeJoined.end(),
                [&](auto timerInfo){ mTimers.push_back(timerInfo);});
  mTimersToBeJoined.clear(); 

  for(std::vector<TimerInfo>::iterator it = mTimers.begin();
      it != mTimers.end();)
  {
    it->timeLeft -= timeMs;
    if(it->timeLeft <= 0)
    {
      it->callback();
      mTimers.erase(it);
    }
    else
    {
      it++;
    }
  }
}

void TimeController::AcceptingBetsTimerCb(TimeExpiredCb callback)
{
  log.debug("Creating an AcceptingBetsTimer");
  mTimersToBeJoined.push_back({callback, ACCEPTING_BETS_TIME_MS});
}

void TimeController::DealerDecisionTimerCb(TimeExpiredCb callback)
{
  log.debug("Creating an DealerDecisionTimer");
  mTimersToBeJoined.push_back({callback, DEALER_DECISION_TIME_MS});
}
  
void TimeController::PlayingUserHandTimerCb(TimeExpiredCb callback)
{
  log.debug("Creating an PlayingUserHandTimerCb");
  mTimersToBeJoined.push_back({callback, PLAYING_USER_HAND_TIME_MS});
}

}
