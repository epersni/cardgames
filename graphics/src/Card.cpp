#include "Card.hpp"

namespace cardgames::graphics
{

Card::Card(const cards::Card card, const ImageFactory::Ptr& imageFactory)
  : mImage(imageFactory->CreateImage("cards/3_of_hearts.png"))
{
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mImage, states);
}

void Card::setPosition(float x, float y)
{
  mImage.setPosition(x,y);
}

}
