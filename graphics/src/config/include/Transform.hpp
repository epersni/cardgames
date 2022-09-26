#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_TRANSFORM_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_TRANSFORM_HPP

namespace cardgames::graphics::config
{

struct Scale
{
  float x;
  float y;
};

struct Position
{
  float x;
  float y;
};

struct Transform
{
  Position position;
  Scale scale;
  float angle;
};

}

#endif
