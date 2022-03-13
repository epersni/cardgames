#ifndef CARDGAMES_BLACKJACK_GAME_PLAY_DECISIONS_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAY_DECISIONS_IF_HPP


//TODO: Is this even used/necessary?
#include <memory>

namespace cardgames::blackjack::game{

struct PlayDecisionsIf
{
  using Ptr = std::shared_ptr<PlayDecisionsIf>;
  
  virtual bool CanHit() const = 0;
  virtual void Hit() = 0;

  virtual bool CanDouble() const = 0;
  virtual void Double() = 0;

  virtual bool CanStand() const = 0;
  virtual void Stand() = 0;

  virtual bool CanSplit() const = 0;
  virtual void Split() = 0;
};

}

#endif


