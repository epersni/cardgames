#ifndef CARDGAMES_CARDS_DECK_HPP
#define CARDGAMES_CARDS_DECK_HPP

#include "DeckIf.hpp"

#include <exception>
#include <vector>

namespace cardgames::cards{

class DeckFactory;

class NoCardsLeftInDeckException : public std::exception
{
  const char* what() const noexcept override
  {
    return "No more cards in deck";
  }
};

class Deck : public DeckIf
{
public:
  friend class DeckFactory;
  
  Card Draw();
  unsigned int CardsLeft() const;
  void Shuffle();
  void PushTop(const Card& card);
  void InsertBottom(const Card& card);

private:
  friend Deck operator+(const Deck& lhs, const Deck& rhs);

  std::vector<Card> mCards;
};


}

#endif
