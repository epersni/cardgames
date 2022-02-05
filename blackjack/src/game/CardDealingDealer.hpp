#ifndef CARDGAMES_BLACKJACK_GAME_CARD_DEALING_DEALER_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_DEALING_DEALER_HPP

#include "CardDealerIf.hpp"
#include "CardProviderIf.hpp"
#include "CardReceiverIf.hpp"
#include "PlayableHandIf.hpp"

#include "../../../cards/include/BlackjackHand.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class CardDealingDealer
  : public CardDealerIf
  , public CardProviderIf
{
public:
  CardDealingDealer(const CardProviderIf::Ptr& cardProvider,
         const std::vector<CardReceiverIf::Ptr>& cardReceivers);
  void DealCards(CardsDealtCb callback);
  cards::Card GetCard(); //TODO: not a good name for this function/interface

private:
  const CardProviderIf::Ptr& mCardProvider;
  const std::vector<CardReceiverIf::Ptr>& mCardReceivers;
};

}

#endif


