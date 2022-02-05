#include "../include/DeckFactory.hpp"

#include <catch2/catch.hpp>

using namespace cardgames::cards;

namespace
{
  const unsigned int NUMBER_OF_CARDS_IN_NORMAL_DECK = 52;
}

TEST_CASE("Creating a normal deck", "[deck-factory]")
{
  Deck deck{DeckFactory::CreateNormalDeck()};
  REQUIRE(deck.CardsLeft() == NUMBER_OF_CARDS_IN_NORMAL_DECK);
}

TEST_CASE("Creating a black-jack deck", "[deck-factory]")
{
  Deck deck{DeckFactory::CreateBlackJackDeck()};
  REQUIRE(deck.CardsLeft() == (NUMBER_OF_CARDS_IN_NORMAL_DECK * 8));
}




