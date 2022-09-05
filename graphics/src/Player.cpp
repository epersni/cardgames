#include "Player.hpp"
#include <iostream> //TODO

namespace cardgames::graphics
{

Player::Player(const blackjack::game::PlayerIf::Ptr& player,
               const ImageFactory::Ptr& imageFactory,
               const TextFactory::Ptr& textFactory)
  : mPlayer(player)
{
  for(const auto &hand : mPlayer->GetHands())
  {
    mHands.push_back(std::make_unique<Hand>(hand, imageFactory, textFactory));
  }
  
  unsigned int handsOffset = 0;
  for(auto& hand : mHands)
  {
    hand->setPosition(0+handsOffset, 0+handsOffset); //TODO: magic number for now, no support (yet) for split hands anyway
    handsOffset += 50;
  }
}

void Player::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(const auto &hand : mHands)
  {
    target.draw(*hand, states);
  }
}

}

