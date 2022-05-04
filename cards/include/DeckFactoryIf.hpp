#ifndef CARDGAMES_CARDS_DECKFACTORY_IF_HPP
#define CARDGAMES_CARDS_DECKFACTORY_IF_HPP

#include "Deck.hpp"

#include <memory>

namespace cardgames::cards
{

struct DeckFactoryIf
{
  using Ptr = std::shared_ptr<DeckFactoryIf>;
  virtual Deck CreateNormalDeck() = 0;
  virtual Deck CreateBlackJackDeck() = 0;
};


}

#endif


