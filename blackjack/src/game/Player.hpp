#ifndef CARDGAMES_BLACKJACK_GAME_PLAYER_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYER_HPP

#include "GameStatePublisherIf.hpp"

namespace cardgames::blackjack::game{

class Player
{
public:
  Player(const GameStatePublisherIf::Ptr& gameStatePublisher);

private:
};

}

#endif

