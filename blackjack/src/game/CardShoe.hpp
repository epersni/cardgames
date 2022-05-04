#ifndef CARDGAMES_BLACKJACK_GAME_CARD_SHOE_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_SHOE_HPP

#include "CardProviderIf.hpp"

#include "../../../cards/include/DeckFactoryIf.hpp"
#include "../../../cards/include/DeckIf.hpp"

namespace cardgames::blackjack::game{

class CardShoe : public CardProviderIf
{
  public:
    CardShoe(cards::DeckFactoryIf::Ptr deckFactory);
    cards::Card GetCard() override;
  private:
    cards::DeckFactoryIf::Ptr mDeckFactory;
    cards::Deck mDeck;
};

}

#endif

