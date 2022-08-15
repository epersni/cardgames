#include "Hand.hpp"

namespace cardgames::graphics
{

Hand::Hand(const blackjack::game::PlayableHandIf::Ptr& playableHand,
           const ImageFactory::Ptr& imageFactory)
  : mImageFactory(imageFactory)
{
  for(const auto& card : playableHand->GetCards())
  {
    mCards.push_back(std::make_shared<Card>(card, mImageFactory));
  }
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
