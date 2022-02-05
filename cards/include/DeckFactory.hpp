#ifndef CARDGAMES_CARDS_DECKFACTORY_HPP
#define CARDGAMES_CARDS_DECKFACTORY_HPP

#include "Deck.hpp"

namespace cardgames::cards
{

class DeckFactory
{
public:
  static Deck CreateNormalDeck();
  static Deck CreateBlackJackDeck();
};


}

#endif

