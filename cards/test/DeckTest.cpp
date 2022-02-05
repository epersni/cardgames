#include "../include/Card.hpp"
#include "../include/Deck.hpp"
#include "../include/DeckFactory.hpp"

#include <algorithm>
#include <catch2/catch.hpp>

using namespace cardgames::cards;

TEST_CASE("Creating empty deck returns 0 in CardsLeft()", "[deck]")
{
  Deck deck;
  REQUIRE(deck.CardsLeft() == 0);
}

TEST_CASE("Insert at bottom increases the number of cards left", "[deck]")
{
  Deck deck;
  REQUIRE(deck.CardsLeft() == 0);
  deck.InsertBottom(Card());
  REQUIRE(deck.CardsLeft() == 1);
}

TEST_CASE("Push card on top increases the number of cards left", "[deck]")
{
  Deck deck;
  REQUIRE(deck.CardsLeft() == 0);
  deck.PushTop(Card());
  REQUIRE(deck.CardsLeft() == 1);
}

TEST_CASE("Draw one card shall decrease number of cards left", "[deck]")
{
  const unsigned numberOfInitialCards = 10;
  Deck deck;
  for(unsigned int i = 0; i < numberOfInitialCards; ++i)
  {
    deck.PushTop(Card());
  }

  REQUIRE(deck.CardsLeft() == numberOfInitialCards);
  
  for(unsigned int i = 1; i <= numberOfInitialCards; ++i)
  {
    (void)deck.Draw();
    REQUIRE(deck.CardsLeft() == (numberOfInitialCards - i));
  }
}

TEST_CASE("Drawn cards are in the reversed order as pushed on top", "[deck]")
{
  std::vector<Card> cards
  {
    {Suit::Hearts, Rank::Ace},
    {Suit::Hearts, Rank::Two},
    {Suit::Hearts, Rank::Three},
    {Suit::Hearts, Rank::Four},
    {Suit::Hearts, Rank::Five},
    {Suit::Hearts, Rank::Six},
  };
  
  Deck deck;
  std::for_each(cards.begin(), cards.end(), [&](auto& c){ deck.PushTop(c); });

  std::vector<Card> drawnCards;
  while(deck.CardsLeft() > 0)
  {
    drawnCards.push_back(deck.Draw());
  }

  std::reverse(cards.begin(), cards.end());

  REQUIRE(drawnCards == cards);
}

TEST_CASE("Drawn cards are in the same order as inserted at bottom", "[deck]")
{
  std::vector<Card> cards
  {
    {Suit::Hearts, Rank::Ace},
    {Suit::Hearts, Rank::Two},
    {Suit::Hearts, Rank::Three},
    {Suit::Hearts, Rank::Four},
    {Suit::Hearts, Rank::Five},
    {Suit::Hearts, Rank::Six},
  };
  
  Deck deck;
  std::for_each(cards.begin(),
                cards.end(),
                [&](auto& c){ deck.InsertBottom(c); });

  std::vector<Card> drawnCards;
  while(deck.CardsLeft() > 0)
  {
    drawnCards.push_back(deck.Draw());
  }

  REQUIRE(drawnCards == cards);
}

TEST_CASE("Draw card when no more cards left shall throw exception", "[deck]")
{
  Deck deck;
  CHECK(deck.CardsLeft() == 0);
  REQUIRE_THROWS_AS(deck.Draw(), NoCardsLeftInDeckException);
}

