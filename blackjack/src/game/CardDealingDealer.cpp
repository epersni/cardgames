#include "CardDealingDealer.hpp"
#include <algorithm>

namespace cardgames::blackjack::game{

CardDealingDealer::CardDealingDealer(const CardProviderIf::Ptr& cardProvider,
               const std::vector<CardReceiverIf::Ptr>& cardReceivers)
  : mCardProvider(cardProvider)
  , mCardReceivers(cardReceivers)
{
}

void CardDealingDealer::DealCards(CardsDealtCb callback)
{
  auto dealIteration = [this](CardReceiverIf::Ptr receiver)
  {
    receiver->ReceiveCard(std::move(mCardProvider->GetCard()));
  };
  std::for_each(mCardReceivers.begin(), mCardReceivers.end(), dealIteration);
  std::for_each(mCardReceivers.begin(), mCardReceivers.end(), dealIteration);
  callback();
}

cards::Card CardDealingDealer::GetCard()
{
  return mCardProvider->GetCard();
}
  
}
