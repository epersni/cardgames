#include "TimeController.hpp"

#include "Logging.hpp"

#include <algorithm>

namespace cardgames::blackjack::game{
namespace{
  logging::Logger log = logging::Logger::createLogger("TimeController");
  const uint32_t ACCEPTING_BETS_TIME_MS = 10000;
  const uint32_t DEALER_DECISION_TIME_MS = 1000;
}

void TimeController::IncrementGameTimeMs(uint32_t timeMs)
{
  log.debug("Updating timers({}) with {} (ms)", mTimers.size(), timeMs);

  for_each(mTimers.begin(),
           mTimers.end(),
           [timeMs](TimerInfo& timer){ timer.timeLeft -= timeMs; });

  //TODO: also call all the callbacks, lol

  remove_if(mTimers.begin(),
            mTimers.end(),
            [](TimerInfo& timer){ return timer.timeLeft <= 0; });
}

void TimeController::AcceptingBetsTimerCb(TimeExpiredCb callback)
{
  log.debug("Creating an AcceptingBetsTimer");
  mTimers.push_back({callback, ACCEPTING_BETS_TIME_MS});
}

void TimeController::DealerDecisionTimerCb(TimeExpiredCb callback)
{
  log.debug("Creating an DealerDecisionTimer");
  mTimers.push_back({callback, DEALER_DECISION_TIME_MS});
}

}
