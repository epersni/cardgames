#ifndef CARDGAMES_BLACKJACK_GAME_GAME_STATE_HPP
#define CARDGAMES_BLACKJACK_GAME_GAME_STATE_HPP

namespace cardgames::blackjack::game{

enum class GameState
{
  AcceptingBets,
  DealingCards,
  PlayersPlaying,
  DealerPlaying,
  Outcome
};

}

#endif

