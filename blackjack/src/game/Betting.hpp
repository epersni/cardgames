#ifndef CARDGAMES_BLACKJACK_GAME_BETTING_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_BETTING_IF_HPP

#include "BettingControlsIf.hpp"

namespace cardgames::blackjack::game{

class Betting : public BettingControlsIf
{
  void DisableAll() override {};
  void OnPlaceBet(OnBetsPlacedCb cb) override { (void)cb; }
};

}

#endif

