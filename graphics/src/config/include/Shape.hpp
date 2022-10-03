#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_SHAPE_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_SHAPE_HPP

#include "Transform.hpp"

#include <cstdint>

namespace cardgames::graphics::config
{

struct Shape
{
  Transform transform;
  uint32_t fillcolor;
  uint32_t outlinecolor;
  float outline;
};

struct Circle
{
  Shape shape;
  uint32_t radius;
  uint32_t points;
};

struct Rectangle
{
  Shape shape;
  Scale size;
};

}

#endif



