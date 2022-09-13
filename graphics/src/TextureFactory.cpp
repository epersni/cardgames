#include "TextureFactory.hpp"

namespace cardgames::graphics
{

TextureFactory::TextureFactory(const std::string& pathPrefix)
  : mPath(pathPrefix)
{
}

sf::Texture& TextureFactory::Load(const std::string& filename)
{
  auto found = mTextureMap.find(filename);
  if(found != mTextureMap.end())
  {
    return *(found->second);
  }
  else
  {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(mPath + filename);
    mTextureMap.insert(std::make_pair(filename, std::move(texture)));
    return Load(filename);
  }
}

}

