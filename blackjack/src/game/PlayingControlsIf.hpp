#ifndef CARDGAMES_BLACKJACK_GAME_PLAYING_CONTROLS_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYING_CONTROLS_IF_HPP

#include <memory>

namespace cardgames::blackjack::game{

struct PlayingControlsIf
{
  using Ptr = std::shared_ptr<PlayingControlsIf>;

  virtual void OnStand(std::function<void()> cb) = 0;
  virtual void OnSplit(std::function<void()> cb) = 0;
  virtual void OnDouble(std::function<void()> cb) = 0;
  virtual void OnHit(std::function<void()> cb) = 0;
  
  virtual void DisableAll() = 0;
};

}

#endif

