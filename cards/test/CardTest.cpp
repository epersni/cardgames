#include "Card.hpp"

#include <catch2/catch.hpp>

using namespace cardgames::cards;

TEST_CASE("All four suits are available", "[cards]")
{
  REQUIRE(Suit::Hearts != Suit::Diamonds);
  REQUIRE(Suit::Hearts != Suit::Clubs);
  REQUIRE(Suit::Hearts != Suit::Spades);
  REQUIRE(Suit::Spades != Suit::Diamonds);
  REQUIRE(Suit::Spades != Suit::Clubs);
  REQUIRE(Suit::Spades != Suit::Hearts);
  REQUIRE(Suit::Clubs != Suit::Diamonds);
  REQUIRE(Suit::Clubs != Suit::Spades);
  REQUIRE(Suit::Clubs != Suit::Hearts);
  REQUIRE(Suit::Diamonds != Suit::Clubs);
  REQUIRE(Suit::Diamonds != Suit::Spades);
  REQUIRE(Suit::Diamonds != Suit::Hearts);
}

TEST_CASE("All ranks shall have proper values", "[cards]")
{
  REQUIRE((int)Rank::Ace == 1);
  REQUIRE((int)Rank::Two == 2);
  REQUIRE((int)Rank::Three == 3);
  REQUIRE((int)Rank::Four == 4);
  REQUIRE((int)Rank::Five == 5);
  REQUIRE((int)Rank::Six == 6);
  REQUIRE((int)Rank::Seven == 7);
  REQUIRE((int)Rank::Eight == 8);
  REQUIRE((int)Rank::Nine == 9);
  REQUIRE((int)Rank::Ten == 10);
  REQUIRE((int)Rank::Jack == 11);
  REQUIRE((int)Rank::Queen == 12);
  REQUIRE((int)Rank::King == 13);
}



