#include "TextFactory.hpp"

#include <filesystem>
#include <string>

namespace cardgames::graphics
{
namespace
{
  const std::string FONT_EXTENSION = ".ttf";
  const std::string DEFAULT_FONT = "default.ttf";
}

TextFactory::TextFactory(const std::string& fontsPath)
  : mFontsPath(fontsPath)
{
  using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
  
  for (const auto& dirEntry : recursive_directory_iterator(mFontsPath))
  {
    const auto& path = dirEntry.path();
    if(path.has_extension() && (path.extension() == FONT_EXTENSION))
    {
      sf::Font font;
      if(font.loadFromFile(path)) //TODO what if else? Log atleast
      {
        mFonts[path.filename()] = font;
      }
    }
  }
}

//TODO: lookup text from language somehow
sf::Text TextFactory::CreateText(const config::Text& config,
                                 const std::string& text)
{
  sf::Text t;
  t.setCharacterSize(config.size);
  t.setFillColor(sf::Color(config.fillcolor));
  t.setFont(mFonts[config.font]);
  t.setOutlineColor(sf::Color(config.outlinecolor));
  t.setOutlineThickness(config.outline);
  t.setPosition(config.transform.position.x, config.transform.position.y);
  t.setRotation(config.transform.angle);
  t.setScale(config.transform.scale.x, config.transform.scale.y);
  t.setString(text);
  t.setStyle(config.style);
  return t;
}

}
