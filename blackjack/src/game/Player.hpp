#ifndef CARDGAMES_BLACKJACK_GAME_PLAYER_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYER_HPP

#include "GameStateDistributorIf.hpp"
#include "GameStateReceiverIf.hpp"

namespace cardgames::blackjack::game{

class Player
  : public std::enable_shared_from_this<Player>
  , public GameStateReceiverIf
{
public:
  Player(const GameStateDistributorIf::Ptr& gameStateDistributor);
  void ReceiveGameState(const GameState newState) override;

private:
};

}

#endif

