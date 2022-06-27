#include "Player.hpp"


namespace cardgames::graphics
{

Player::Player(const blackjack::game::PlayerIf::Ptr& player)
  : mPlayer(player)
{

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

}

