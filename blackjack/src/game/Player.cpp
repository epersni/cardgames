#include "Player.hpp"

namespace cardgames::blackjack::game{

Player::Player(const GameStateDistributorIf::Ptr& gameStateDistributor)
{
  gameStateDistributor->Subscribe(shared_from_this());
}

void Player::ReceiveGameState(const GameState newState)
{
  (void)newState;
}

}
