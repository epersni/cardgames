#ifndef CARDGAMES_GRAPHICS_TEXTCONFIG_HPP
#define CARDGAMES_GRAPHICS_TEXTCONFIG_HPP

#include <SFML/Graphics/Text.hpp>

#include <string>

namespace cardgames::graphics
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

struct TextConfig
{
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


