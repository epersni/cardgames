#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_BUTTON_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_BUTTON_HPP

#include "Button.hpp"
#include "Image.hpp"
#include "Text.hpp"
#include "Transform.hpp"

#include <SFML/Graphics/Text.hpp>

namespace cardgames::graphics::config
{

struct Button
{
  Transform transform;
  Text text;
  Image imagePressed;
  Image imageReleased;
};

}

#endif
