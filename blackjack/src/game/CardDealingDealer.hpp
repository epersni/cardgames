#ifndef CARDGAMES_BLACKJACK_GAME_CARD_DEALING_DEALER_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_DEALING_DEALER_HPP

#include "CardDealerIf.hpp"
#include "CardProviderIf.hpp"
#include "CardReceiverIf.hpp"

#include "../../../cards/include/DeckIf.hpp"
#include "../../../cards/include/BlackjackHand.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class CardDealingDealer
  : public CardDealerIf
  , public CardProviderIf
{
public:
  CardDealingDealer(const cards::DeckIf::Ptr& deck,
                    const std::vector<CardReceiverIf::Ptr>& cardReceivers);
  void DealCards(CardsDealtCb callback) override;
  cards::Card GetCard() override; //TODO: not a good name for this function/interface

private:
  const cards::DeckIf::Ptr& mDeck;
  const std::vector<CardReceiverIf::Ptr>& mCardReceivers;
};

}

#endif


