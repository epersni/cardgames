#ifndef CARDGAMES_BLACKJACK_GAME_BETTING_CONTROLS_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_BETTING_CONTROLS_IF_HPP

#include <functional>
#include <memory>

namespace cardgames::blackjack::game{

struct BettingControlsIf
{
  using Ptr = std::shared_ptr<BettingControlsIf>;
  virtual void DisableAll() = 0;
  using OnBetsPlacedCb = std::function<void(unsigned int)>;
  virtual void OnPlaceBet(OnBetsPlacedCb cb) = 0;
};

}

#endif
