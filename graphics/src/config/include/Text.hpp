#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_TEXT_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_TEXT_HPP

#include "Transform.hpp"

#include <SFML/Graphics/Text.hpp>

#include <cstdint>
#include <string>

namespace cardgames::graphics::config
{

struct TextStyle
{
  bool bold;
  bool italic;
  bool strikethrough;
  bool underlined;
  operator uint32_t() const
  {  
    uint32_t style = sf::Text::Regular;
    style += bold ? sf::Text::Bold : 0;
    style += italic ? sf::Text::Italic : 0;
    style += underlined ? sf::Text::Underlined : 0;
    style += strikethrough? sf::Text::StrikeThrough : 0;
    return style;
  }
};

enum class TextAlignment { Left, Center, Right };

struct Text
{
  Transform transform;
  std::string font;
  unsigned int size;
  uint32_t fillcolor;
  uint32_t outlinecolor;
  float outline;
  TextStyle style;
  TextAlignment alignment;
};

}

#endif


