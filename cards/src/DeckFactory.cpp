#include "../include/DeckFactory.hpp"

#include <array>

namespace cardgames::cards
{

namespace
{
  const int NUMBER_OF_RANKS = 13;
  const int NUMBER_OF_SUITS = 4;
}

Deck DeckFactory::CreateNormalDeck()
{
  std::array<Rank, NUMBER_OF_RANKS> allRanks =
  {
    Rank::Two,
    Rank::Three,
    Rank::Four, 
    Rank::Five, 
    Rank::Six,  
    Rank::Seven,
    Rank::Eight,
    Rank::Nine, 
    Rank::Ten,  
    Rank::Jack, 
    Rank::Queen, 
    Rank::King,
    Rank::Ace  
  };

  std::array<Suit, 4> allSuits = 
  {
    Suit::Hearts,
    Suit::Diamonds,
    Suit::Clubs,
    Suit::Spades
  };
  
  Deck deck;

  for (auto&& suit : allSuits)
  {
    for (auto&& rank : allRanks)
    {
      deck.PushTop({suit, rank});
    }
  }

  return deck;
}

Deck DeckFactory::CreateBlackJackDeck()
{
  return CreateNormalDeck() + CreateNormalDeck() + CreateNormalDeck() + 
         CreateNormalDeck() + CreateNormalDeck() + CreateNormalDeck() + 
         CreateNormalDeck() + CreateNormalDeck();
}

}
