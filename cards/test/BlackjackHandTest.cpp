#include "../include/BlackjackHand.hpp"

#include <algorithm>
#include <catch2/catch.hpp>

using namespace cardgames::cards;

TEST_CASE("Creating a BlackJackHand", "[BlackjackHand]")
{
  BlackjackHand hand;
  REQUIRE(hand.GetTotal() == 0);
}

TEST_CASE("Adding cards shall get the same cards back on GetCards()", "[BlackjackHand]")
{
  std::vector<Card> cards
  {
    { Suit::Hearts, Rank::Ace },
    { Suit::Hearts, Rank::Two },
    { Suit::Hearts, Rank::Three },
    { Suit::Hearts, Rank::Four },
    { Suit::Hearts, Rank::Five },
    { Suit::Hearts, Rank::Six },
    { Suit::Spades, Rank::Ace },
    { Suit::Spades, Rank::Two },
    { Suit::Spades, Rank::Three },
    { Suit::Spades, Rank::Four },
    { Suit::Spades, Rank::Five },
    { Suit::Spades, Rank::Six },
  };
  
  BlackjackHand hand;
  std::for_each(cards.begin(), cards.end(), [&](auto& c){ hand.AddCard(c); });

  REQUIRE(hand.GetCards() == cards);
}

TEST_CASE("Adding card with rank 2 shall give 2 as ideal total", "[BlackjackHand]")
{
  BlackjackHand hand;
  hand.AddCard({Suit::Hearts, Rank::Two});
  REQUIRE(hand.GetTotal() == 2);
}

TEST_CASE("Hand with one ace shall give 11 as ideal total", "[BlackjackHand]")
{
  BlackjackHand hand1;
  BlackjackHand hand2;
  BlackjackHand hand3;
  BlackjackHand hand4;
  hand1.AddCard({Suit::Hearts, Rank::Ace});
  hand2.AddCard({Suit::Clubs, Rank::Ace});
  hand3.AddCard({Suit::Spades, Rank::Ace});
  hand4.AddCard({Suit::Diamonds, Rank::Ace});
  REQUIRE(hand1.GetTotal() == 11);
  REQUIRE(hand2.GetTotal() == 11);
  REQUIRE(hand3.GetTotal() == 11);
  REQUIRE(hand4.GetTotal() == 11);
}

TEST_CASE("Hand with two aces shall give 12 as ideal total", "[BlackjackHand]")
{
  BlackjackHand hand;
  hand.AddCard({Suit::Hearts, Rank::Ace});
  hand.AddCard({Suit::Clubs, Rank::Ace});
  REQUIRE(hand.GetTotal() == 12);
}

TEST_CASE("Adding aces shall get the same cards back", "[BlackjackHand]")
{
  std::vector<Card> aces
  {
    {Suit::Hearts, Rank::Ace},
    {Suit::Clubs, Rank::Ace},
    {Suit::Spades, Rank::Ace},
    {Suit::Diamonds, Rank::Ace},
    {Suit::Hearts, Rank::Ace},
    {Suit::Clubs, Rank::Ace},
    {Suit::Spades, Rank::Ace},
    {Suit::Spades, Rank::Ace},
    {Suit::Diamonds, Rank::Ace}
  };
  
  BlackjackHand hand;
  std::for_each(aces.begin(), aces.end(), [&](auto& c){ hand.AddCard(c); });
  
  REQUIRE(hand.GetTotal() == 19);

  REQUIRE(hand.GetCards() == aces);
}

TEST_CASE("Hand with one face card shall give 10 as ideal total", "[BlackjackHand]")
{
  BlackjackHand hand1;
  BlackjackHand hand2;
  BlackjackHand hand3;
  hand1.AddCard({Suit::Hearts, Rank::Jack});
  hand2.AddCard({Suit::Hearts, Rank::Queen});
  hand3.AddCard({Suit::Hearts, Rank::King});
  REQUIRE(hand1.GetTotal() == 10);
  REQUIRE(hand2.GetTotal() == 10);
  REQUIRE(hand3.GetTotal() == 10);
}
