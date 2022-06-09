#ifndef CARDGAMES_BLACKJACK_GAME_PLAYING_CONTROLS_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYING_CONTROLS_IF_HPP

#include <memory>

namespace cardgames::blackjack::game{

struct PlayingControlsIf
{
  using Ptr = std::shared_ptr<PlayingControlsIf>;
  using ButtonPressedCb = std::function<void()>;

  virtual void OnStand(ButtonPressedCb cb) = 0;
  virtual void OnSplit(ButtonPressedCb cb) = 0;
  virtual void OnDouble(ButtonPressedCb cb) = 0;
  virtual void OnHit(ButtonPressedCb cb) = 0;
  
  virtual void DisableAll() = 0;
};

}

#endif

