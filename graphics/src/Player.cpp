#include "Player.hpp"

namespace cardgames::graphics
{

Player::Player(const blackjack::game::PlayerIf::Ptr& player,
               const TextureFactoryIf::Ptr& textureFactory,
               const TextFactory::Ptr& textFactory,
               const config::Player& config)
  : mPlayer(player)
{
  config::Position nextHandOffset = { 0, 0 };
  for(const auto &hand : mPlayer->GetHands())
  {
    auto handNode = Hand(hand, textureFactory, textFactory, config.hand);
    handNode.setPosition(nextHandOffset.x, nextHandOffset.y);
    nextHandOffset.x += config.handsOffset.x;
    nextHandOffset.y += config.handsOffset.y;
    AddChild(std::make_unique<Hand>(std::move(handNode)));
  }

  setPosition(config.transform.position.x, config.transform.position.y);
  setScale(config.transform.scale.x, config.transform.scale.x);
  rotate(config.transform.angle);
}

void Player::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  /* Do nothing (cards are drawn in the child nodes) */
}

}

