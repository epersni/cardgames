#include "Button.hpp"

namespace cardgames::graphics
{

Button::Button(const config::Button& config,
               const TextureFactoryIf::Ptr& textureFactory,
               const TextFactoryIf::Ptr& textFactory)
  : mText(textFactory->CreateText(config.text, "Hit"))
  , mSpritePressed(textureFactory->Load(config.imagePressed.filename))
  , mSpriteReleased(textureFactory->Load(config.imageReleased.filename))
{
  Transform(config.transform);

  Transform(config.imageReleased.transform, mSpriteReleased);
  Align(mSpriteReleased);
  CenterOrigin(mSpriteReleased);

  Transform(config.imagePressed.transform, mSpritePressed);
  Align(mSpritePressed);
  CenterOrigin(mSpritePressed);

  Transform(config.text.transform, mText);
  Align(mText);
  CenterOrigin(mText);
}

void Button::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  //target.draw(mSpritePressed, states); //TODO: make button appear to be pressed/relased
  target.draw(mSpriteReleased, states);
  target.draw(mText, states);
}

}

