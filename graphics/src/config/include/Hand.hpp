#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_HAND_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_HAND_HPP

#include "Transform.hpp"

namespace cardgames::graphics::config
{

struct Hand
{
  Transform transform;
  Position cardsOffset;
  Scale cardsScale;
  Text sumText;
};

}

#endif
