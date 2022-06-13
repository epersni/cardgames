#include "Hand.hpp"

namespace cardgames::graphics
{

void Hand::addCard(/*cards::Card card*/)
{
  mCards.emplace_back(
      std::make_shared<Image>("/home/nicklas/src/cardgames/graphics/images/cards/3_of_hearts.png"));
  setPosition(0,0);
}

void Hand::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(const auto& card : mCards)
  {
    target.draw(*card, states);
  }
}

void Hand::setPosition(float x, float y)
{
  float offsetY = 0.0;
  float offsetX = 0.0;
  for(const auto& card : mCards)
  {
    card->setPosition(x+offsetX,y+offsetY);
    offsetY += 10;
    offsetX += 100;
  }
}

}
