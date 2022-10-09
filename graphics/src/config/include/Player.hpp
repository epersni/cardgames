#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_PLAYER_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_PLAYER_HPP

#include "Button.hpp"
#include "Hand.hpp"
#include "Shape.hpp"

namespace cardgames::graphics::config
{

struct Player
{
  Transform transform;
  Hand hand;
  Position handsOffset;
  Rectangle headUpDisplayBox;
  Text instruction;
  Text name;
  Text credits;
  Button buttons[4];
};

}

#endif
