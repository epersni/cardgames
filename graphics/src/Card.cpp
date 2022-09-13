#include "Card.hpp"

namespace cardgames::graphics
{
namespace
{
  std::string getSuitName(const cards::Suit suit)
  {
    switch(suit)
    {
      case cards::Suit::Hearts:
        return "hearts";
      case cards::Suit::Diamonds:
        return "diamonds";
      case cards::Suit::Clubs:
        return "clubs";
      case cards::Suit::Spades:
        return "spades";
    }
  }

  std::string getRank(const cards::Rank rank)
  {
    switch(rank)
    {
      case cards::Rank::Ace:
        return "ace";
      case cards::Rank::Two:
        return "2";
      case cards::Rank::Three:
        return "3";
      case cards::Rank::Four:
        return "4";
      case cards::Rank::Five:
        return "5";
      case cards::Rank::Six:
        return "6";
      case cards::Rank::Seven:
        return "7";
      case cards::Rank::Eight:
        return "8";
      case cards::Rank::Nine:
        return "9";
      case cards::Rank::Ten:
        return "10";
      case cards::Rank::Jack:
        return "jack";
      case cards::Rank::Queen:
        return "queen";
      case cards::Rank::King:
        return "king";
    }
  }

  const std::string FILE_EXTENSION = ".png";

  std::string getCardFileName(const cards::Card card)
  {
    return getRank(card.rank) + "_of_" + getSuitName(card.suit) + FILE_EXTENSION;
  }
}

Card::Card(const cards::Card card, const TextureFactoryIf::Ptr& textureFactory)
  : mSprite(textureFactory->Load("cards/" + getCardFileName(card)))
{
  mSprite.setScale(0.5, 0.5); //TODO: configurable?
}

void Card::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mSprite, states);
}

}
