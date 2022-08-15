#include "Player.hpp"
#include <iostream> //TODO

namespace cardgames::graphics
{

Player::Player(const blackjack::game::PlayerIf::Ptr& player,
               const ImageFactory::Ptr& imageFactory)
  : mPlayer(player)
{
  for(const auto &hand : mPlayer->GetHands())
  {
    mHands.emplace_back(hand, imageFactory);
  }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(const auto &hand : mHands)
  {
    target.draw(hand, states);
  }
}

void Player::setPosition(float x, float y)
{
  for(auto &hand : mHands)
  {
    hand.setPosition(x,y);
  }
}

}

