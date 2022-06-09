#include "CardShoe.hpp"

namespace cardgames::blackjack::game{

CardShoe::CardShoe(cards::DeckFactoryIf::Ptr deckFactory)
  : mDeckFactory(deckFactory)
  , mDeck(mDeckFactory->CreateBlackJackDeck())
{
  mDeck.Shuffle();
}

cards::Card CardShoe::GetCard()
{
  if(mDeck.CardsLeft() == 0)
  {
    mDeck = mDeckFactory->CreateBlackJackDeck();
    mDeck.Shuffle(); //TODO: unit test that we do this
  }
  return mDeck.Draw();
}

}
