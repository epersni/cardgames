#ifndef CARDGAMES_CARDS_DECK_IF_HPP
#define CARDGAMES_CARDS_DECK_IF_HPP

#include "Card.hpp"

namespace cardgames::cards
{

struct DeckIf
{
  virtual void Shuffle() = 0;
  virtual Card Draw() = 0;
  virtual unsigned int CardsLeft() const = 0;
};

}

#endif


