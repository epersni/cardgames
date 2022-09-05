#include "Hand.hpp"

#include <string>

namespace cardgames::graphics
{

Hand::Hand(const blackjack::game::PlayableHandIf::Ptr& playableHand,
           const ImageFactory::Ptr& imageFactory,
           const TextFactory::Ptr& textFactory)
  : mHand(playableHand)
  , mSumText(textFactory->CreateText(
        "player.hand.total",
        playableHand->GetTotal() ==  0 ? "" : std::to_string(playableHand->GetTotal())))
{
  for(const auto& card : playableHand->GetCards())
  {
    mCards.push_back(std::make_shared<Card>(card, imageFactory));
  }
}

void Hand::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(const auto& card : mCards)
  {
    target.draw(*card, states);
  }
  target.draw(mSumText, states);
}

void Hand::setPosition(float x, float y)
{
  float offsetX = 0.0;
  float offsetY = 80;
  for(const auto& card : mCards)
  {
    card->setPosition(x+offsetX,y+offsetY);
    offsetY += 10;
    offsetX += 100;
  }
  mSumText.setPosition(190, 0);
}

}
