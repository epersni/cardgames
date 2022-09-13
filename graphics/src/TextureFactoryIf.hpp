#ifndef CARDGAMES_GRAPHICS_TEXTURE_FACTORY_IF_HPP
#define CARDGAMES_GRAPHICS_TEXTURE_FACTORY_IF_HPP

#include <SFML/Graphics/Texture.hpp>

#include <memory>
#include <string>

namespace cardgames::graphics
{

struct TextureFactoryIf 
{
  using Ptr = std::shared_ptr<TextureFactoryIf>;
  virtual sf::Texture& Load(const std::string& filename) = 0;
};

}

#endif

