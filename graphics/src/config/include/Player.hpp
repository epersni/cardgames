#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_PLAYER_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_PLAYER_HPP

#include "Hand.hpp"

namespace cardgames::graphics::config
{

struct Player
{
  Transform transform;
  Hand hand;
  Position handsOffset;
};

}

#endif
