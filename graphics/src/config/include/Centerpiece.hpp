#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_CENTERPIECE_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_CENTERPIECE_HPP

#include "Text.hpp"
#include "Transform.hpp"
#include "Shape.hpp"

namespace cardgames::graphics::config
{

struct Centerpiece
{
  Transform transform;
  Circle circle;
  Text title;
  Text row1;
  Text row2;
};

}

#endif

