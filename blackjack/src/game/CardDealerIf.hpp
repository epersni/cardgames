#ifndef CARDGAMES_BLACKJACK_GAME_CARD_DEALER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_DEALER_IF_HPP

#include <functional>
#include <memory>

namespace cardgames::blackjack::game{

struct CardDealerIf
{
  using Ptr = std::shared_ptr<CardDealerIf>;
  using CardsDealtCb = std::function<void()>;
  virtual void DealCards(CardsDealtCb callback) = 0;
};

}

#endif


