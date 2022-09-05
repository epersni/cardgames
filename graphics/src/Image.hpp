#ifndef CARDGAMES_GRAPHICS_IMAGE_HPP
#define CARDGAMES_GRAPHICS_IMAGE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <string>

namespace cardgames::graphics
{

class Image 
  : public sf::Drawable
  , public sf::Transformable
{
  public:
    Image(const std::string& filepath);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void setScale(float x, float y);
    void setPosition(float x, float y);

  private:
    const std::string mPath;
    sf::Texture mTexture;
    sf::Sprite mSprite;
};

}

#endif
