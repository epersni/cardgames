#ifndef CARDGAMES_BLACKJACK_GAME_CARD_DEALING_DEALER_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_DEALING_DEALER_HPP

#include "CardDealerIf.hpp"
#include "CardProviderIf.hpp"
#include "CardReceiverIf.hpp"
#include "DealingRoundIf.hpp"

#include "../../../cards/include/BlackjackHand.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class CardDealingDealer
  : public CardDealerIf
  , public CardProviderIf
  , public DealingRoundIf
{
public:
  CardDealingDealer(const CardProviderIf::Ptr& cardProvider);
  void DealCards(CardsDealtCb callback) override;
  cards::Card GetCard() override; //TODO: not a good name for this function/interface
  void JoinNextDealingRound(CardReceiverIf::Ptr cardReceiver) override;

private:
  const CardProviderIf::Ptr mCardProvider;
  std::vector<CardReceiverIf::Ptr> mCardReceivers;
};

}

#endif


