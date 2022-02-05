#ifndef CARDGAMES_BLACKJACK_GAME_CARD_RECEIVER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_RECEIVER_IF_HPP

#include "../../../cards/include/Card.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct CardReceiverIf
{
  using Ptr = std::shared_ptr<CardReceiverIf>;
  virtual void ReceiveCard(const cards::Card card) = 0;
};

}

#endif
