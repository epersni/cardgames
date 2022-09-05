#ifndef CARDGAMES_GRAPHICS_TEXTFACTORY_HPP
#define CARDGAMES_GRAPHICS_TEXTFACTORY_HPP

#include "TextConfig.hpp"
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
    TextFactoryIf::Text CreateText(const std::string& textName,
                                   const std::string& text) override;
  private:
    const std::string mFontsPath;
    std::unordered_map<std::string, sf::Font> mFonts;
    std::unordered_map<std::string, TextConfig> mConfigs;
    
    TextConfig loadTextConfig(const std::string& textName);
    TextFactoryIf::Text createText(const TextConfig& textConfig,
                                   const std::string& text);
};

}

#endif



