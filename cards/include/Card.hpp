#ifndef CARDGAMES_CARDS_CARD_HPP
#define CARDGAMES_CARDS_CARD_HPP

namespace cardgames::cards
{
  
enum class Suit
{
  Hearts,
  Diamonds,
  Clubs,
  Spades
};

enum class Rank
{ 
  Ace   = 1,
  Two   = 2,
  Three = 3,
  Four  = 4,
  Five  = 5,
  Six   = 6,
  Seven = 7,
  Eight = 8,
  Nine  = 9,
  Ten   = 10,
  Jack  = 11,
  Queen = 12,
  King  = 13
};

struct Card
{
  Suit suit = Suit::Spades;
  Rank rank = Rank::Ace;
};

bool operator==(const Card& lhs, const Card& rhs);

}

#endif
