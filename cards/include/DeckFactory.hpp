#ifndef CARDGAMES_CARDS_DECKFACTORY_HPP
#define CARDGAMES_CARDS_DECKFACTORY_HPP

#include "Deck.hpp"
#include "DeckFactoryIf.hpp"

namespace cardgames::cards
{

class DeckFactory : public DeckFactoryIf
{
public:
  Deck CreateNormalDeck() override;
  Deck CreateBlackJackDeck() override;
};


}

#endif

