#ifndef CARDGAMES_BLACKJACK_GAME_PLAYABLEHAND_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYABLEHAND_IF_HPP

#include "../../../cards/include/BlackjackHandIf.hpp"
#include "../../../cards/include/Card.hpp"

#include <functional>
#include <memory>

namespace cardgames::blackjack::game{

struct PlayableHandIf
{
  using Ptr = std::shared_ptr<PlayableHandIf>;
  using DonePlayingCb = std::function<void()>;
  virtual void Play(DonePlayingCb callback) = 0;
  virtual unsigned int GetTotal() const = 0 ;
  virtual std::vector<cards::Card> GetCards() const = 0;
  virtual cards::BlackjackHandIf::Status GetStatus() const = 0;
};

}

#endif
