#ifndef CARDGAMES_GRAPHICS_BUTTON_HPP
#define CARDGAMES_GRAPHICS_BUTTON_HPP

#include "Node.hpp"
#include "TextFactoryIf.hpp"
#include "TextureFactoryIf.hpp"

#include "config/include/Button.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

namespace cardgames::graphics
{

class Button : public Node
{
  public:
    Button(
        const config::Button& config,
        const TextureFactoryIf::Ptr& textureFactory,
        const TextFactoryIf::Ptr& textFactory);
  private:
    sf::Text mText;
    sf::Sprite mSpritePressed;
    sf::Sprite mSpriteReleased;
    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}

#endif


