#include "CardDealingDealer.hpp"
#include <algorithm>

namespace cardgames::blackjack::game{

CardDealingDealer::CardDealingDealer(const cards::DeckIf::Ptr& deck,
               const std::vector<CardReceiverIf::Ptr>& cardReceivers)
  : mDeck(deck)
  , mCardReceivers(cardReceivers)
{
}

void CardDealingDealer::DealCards(CardsDealtCb callback)
{
  auto dealIteration = [this](CardReceiverIf::Ptr receiver)
  {
    receiver->ReceiveCard(std::move(GetCard()));
  };
  std::for_each(mCardReceivers.begin(), mCardReceivers.end(), dealIteration);
  std::for_each(mCardReceivers.begin(), mCardReceivers.end(), dealIteration);
  callback();
}

cards::Card CardDealingDealer::GetCard()
{
  if(mDeck->CardsLeft() == 0)
  {
    mDeck->Shuffle();
  }
  return mDeck->Draw();
}
  
}
