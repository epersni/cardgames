#ifndef CARDGAMES_GRAPHICS_TEXTFACTORY_IF_HPP
#define CARDGAMES_GRAPHICS_TEXTFACTORY_IF_HPP

#include "config/include/Text.hpp"

#include <SFML/Graphics/Text.hpp>

#include <memory>
#include <string>

namespace cardgames::graphics
{

struct TextFactoryIf
{
  using Ptr = std::shared_ptr<TextFactoryIf>;
  using Text = sf::Text;
  virtual Text CreateText(const config::Text& config,
                          const std::string& text) = 0;
};

}

#endif

