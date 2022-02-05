#include "../include/Deck.hpp"

namespace cardgames::cards
{

Card Deck::Draw()
{
  if(!mCards.empty())
  {
    Card card = mCards.front();
    mCards.erase(mCards.begin());
    return card;
  }
  throw NoCardsLeftInDeckException();
}

unsigned int Deck::CardsLeft() const
{ 
  return mCards.size();
}

void Deck::PushTop(const Card& card)
{ 
  mCards.insert(mCards.begin(), card);
}

void Deck::InsertBottom(const Card& card)
{ 
  mCards.push_back(card);
}

void Deck::Shuffle()
{
  //TODO: add shuffle + unit test
}

Deck operator+(const Deck& lhs, const Deck& rhs)
{
  Deck result;
  result.mCards.insert(result.mCards.end(),
                       lhs.mCards.begin(), 
                       lhs.mCards.end());
  result.mCards.insert(result.mCards.end(),
                       rhs.mCards.begin(), 
                       rhs.mCards.end());
  return result;
}

}
