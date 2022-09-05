#ifndef CARDGAMES_GRAPHICS_TEXTFACTORY_IF_HPP
#define CARDGAMES_GRAPHICS_TEXTFACTORY_IF_HPP

#include <SFML/Graphics/Text.hpp>

#include <memory>
#include <string>

namespace cardgames::graphics
{

struct TextFactoryIf
{
  using Ptr = std::shared_ptr<TextFactoryIf>;
  using Text = sf::Text;
  virtual Text CreateText(const std::string& textName,
                          const std::string& text) = 0;
};

}

#endif

