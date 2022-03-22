#ifndef CARDGAMES_BLACKJACK_GAME_GAME_STATE_DISTRIBUTOR_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_STATE_DISTRIBUTOR_HPP

#include "GameStatePublisherIf.hpp"
#include "GameStateReceiverIf.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class GameStateDistributor 
  : public GameStateReceiverIf
  , public GameStatePublisherIf
{
public:
  void Subscribe(GameStateChangeCb cb) override;
  void ReceiveGameState(const GameState newState);
  
private:
  std::vector<GameStateChangeCb> mCallbacks;
};

}

#endif

