#ifndef CARDGAMES_BLACKJACK_GAME_GAME_INCLUDE_PLAYERIF_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_INCLUDE_PLAYERIF_HPP

#include "PlayableHandIf.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct PlayerIf
{
  using Ptr = std::shared_ptr<PlayerIf>;
  virtual std::vector<PlayableHandIf::Ptr> GetHands() const = 0;
};

}

#endif


