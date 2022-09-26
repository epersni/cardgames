#ifndef CARDGAMES_GRAPHICS_TEXTFACTORY_HPP
#define CARDGAMES_GRAPHICS_TEXTFACTORY_HPP

#include "TextFactoryIf.hpp"

#include <SFML/Graphics/Font.hpp>

#include <string>
#include <unordered_map>

namespace cardgames::graphics
{

class TextFactory : public TextFactoryIf
{
  public:
    TextFactory(const std::string& fontsPath);
    TextFactoryIf::Text CreateText(const config::Text& config,
                                   const std::string& text) override;
  private:
    const std::string mFontsPath;
    std::unordered_map<std::string, sf::Font> mFonts;
    
};

}

#endif



