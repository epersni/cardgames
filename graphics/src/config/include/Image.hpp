#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_IMAGE_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_IMAGE_HPP

#include "Transform.hpp"

#include <string>

namespace cardgames::graphics::config
{

struct Image
{
  Transform transform;
  std::string filename;
};

}

#endif

