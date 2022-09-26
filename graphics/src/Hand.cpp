#include "Hand.hpp"

#include <string>

namespace cardgames::graphics
{

Hand::Hand(const blackjack::game::PlayableHandIf::Ptr& playableHand,
           const TextureFactoryIf::Ptr& textureFactory,
           const TextFactory::Ptr& textFactory,
           const config::Hand& config)
  : mHand(playableHand)
  , mSumText(textFactory->CreateText(
        config.sumText, playableHand->GetTotal() ==  0 ? 
          "" : std::to_string(playableHand->GetTotal())))
{
  config::Position nextCardOffset = { 0, 0 };
  for(const auto& card : playableHand->GetCards())
  {
    auto cardNode = Card(card, textureFactory);
    cardNode.setPosition(nextCardOffset.x, nextCardOffset.y);
    cardNode.setScale(config.cardsScale.x, config.cardsScale.y);
    nextCardOffset.x += config.cardsOffset.x;
    nextCardOffset.y += config.cardsOffset.y;
    AddChild(std::make_unique<Card>(std::move(cardNode)));
  }
  
  CenterOrigin(mSumText);
  Transform(config.transform);
}

void Hand::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mSumText, states);
}

}
