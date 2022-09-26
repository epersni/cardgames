#include "Dealer.hpp"

namespace cardgames::graphics
{

Dealer::Dealer(const blackjack::game::PlayableHandIf::Ptr& dealerHand,
               const ImageFactory::Ptr& imageFactory,
               const TextFactory::Ptr& textFactory)
  : mHand(dealerHand, imageFactory, textFactory)
{
  CenterOrigin(mHand);
}

void Player::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(*mHand, states);
}

}

