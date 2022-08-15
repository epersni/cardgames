#include "Image.hpp"

namespace cardgames::graphics
{

Image::Image(const std::string& filepath)
  : mPath(filepath)
{
  if (!mTexture.loadFromFile(mPath))
  {
    //TODO: Now what?
  }
  //mTexture.setSmooth(true);
  mSprite.setTexture(mTexture);
}

void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mSprite, states);
}

void Image::setPosition(float x, float y)
{
  float offsetY = 0.0;
  float offsetX = 0.0;
  mSprite.setPosition(x+offsetX,y+offsetY);
}

}
