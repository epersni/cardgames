#include "Player.hpp"

namespace cardgames::graphics
{

Player::Player(const blackjack::game::PlayerIf::Ptr& player,
               const TextureFactoryIf::Ptr& textureFactory,
               const TextFactory::Ptr& textFactory)
  : mPlayer(player)
{
  for(const auto &hand : mPlayer->GetHands())
  {
    mHands.push_back(std::make_unique<Hand>(hand, textureFactory, textFactory));
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

