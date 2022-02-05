#ifndef CARDGAMES_BLACKJACK_GAME_GAME_STATE_DISTRIBUTOR_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_STATE_DISTRIBUTOR_HPP

#include "GameStateDistributorIf.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class GameStateDistributor : public GameStateDistributorIf
{
public:
  void Subscribe(const GameStateReceiverIf::Ptr& receiver);
  void ReceiveGameState(const GameState newState); //TODO: not really good that this function is public, basically it is only Game.cpp that shall be allowed to call this
  
private:
  std::vector<GameStateReceiverIf::Ptr> mReceivers;
};

}

#endif

