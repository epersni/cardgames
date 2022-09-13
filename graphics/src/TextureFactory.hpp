#ifndef CARDGAMES_GRAPHICS_TEXTURE_FACTORY_HPP
#define CARDGAMES_GRAPHICS_TEXTURE_FACTORY_HPP

#include "TextureFactoryIf.hpp"

#include <SFML/Graphics/Texture.hpp>

#include <unordered_map>
#include <string>

namespace cardgames::graphics
{

class TextureFactory : public TextureFactoryIf
{
public:
  TextureFactory(const std::string& pathPrefix);
  sf::Texture& Load(const std::string& filename) override;
private:
  std::string mPath;
  std::unordered_map<std::string, std::unique_ptr<sf::Texture>> mTextureMap;
};

}

#endif


