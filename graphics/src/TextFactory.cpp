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

TextConfig TextFactory::loadTextConfig(const std::string& textName)
{
  //TODO: hard coded 'player.hand.total' for now, shall have config file for this

  if(textName == "player.hand.total")
  {
      return {
        "magic_retro.ttf",
        50,
        0xff0000ff,
        0xffffffff,
        1,
        false,
        false,
        false,
        false};
  }
  else
  {
      return {
        "magic_retro.ttf",
        50,
        0xff0000ff,
        0xffffffff,
        1,
        false,
        false,
        false,
        false};
  }
}

sf::Text TextFactory::CreateText(const std::string& textConfig,
                                            const std::string& text)
{
  if(mConfigs.find(textConfig) == mConfigs.end())
  {
    //TODO: log this
    mConfigs[textConfig] = loadTextConfig(textConfig);
  }
  return createText(mConfigs[textConfig], text);
}

sf::Text TextFactory::createText(const TextConfig& textConfig,
                                            const std::string& text)
{
  sf::Text t;
  t.setFont(mFonts[textConfig.font]);
  t.setCharacterSize(textConfig.size);
  t.setFillColor(sf::Color(textConfig.fillcolor));
  t.setOutlineColor(sf::Color(textConfig.outlinecolor));
  t.setOutlineThickness(textConfig.outline);
  t.setStyle(textConfig.style);
  t.setString(text);
  return t;
}

}
