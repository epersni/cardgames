#include "../include/BlackjackHand.hpp"

#include <algorithm>
#include <numeric>

namespace cardgames::cards
{

unsigned int BlackjackHand::GetTotal() const 
{
  return std::accumulate(mValues.begin(), mValues.end(), 0);
}
  
void BlackjackHand::AddCard(const Card& card)
{
  mCards.push_back(card);
  mValues.push_back(cardToValue(card));
  if(GetTotal() > 21)
  {
    auto foundAce =  std::find_if(mValues.begin(),
                                  mValues.end(),
                                  [](unsigned int i){ return i == 11; });
    if(foundAce != mValues.end())
    {
      mValues.erase(foundAce);
      mValues.push_back(1);
    }
  }
}

//TODO: FIX AND UNIT TEST
BlackjackHandIf::Status BlackjackHand::GetStatus() const 
{
  if(GetTotal() > 21)
  {
    return BlackjackHandIf::Status::Busted;
  }
  else if((GetTotal() == 21) && (mCards.size() == 2))
  {
    return BlackjackHandIf::Status::BlackJack;
  }
  return BlackjackHandIf::Status::Numeric; 
}

std::vector<Card> BlackjackHand::GetCards() const
{
  return mCards;
}

unsigned int BlackjackHand::cardToValue(const Card& card)
{
  unsigned int result = 0;
  switch(card.rank)
  {
    case cards::Rank::Ace:   result =  11; break;
    case cards::Rank::Two:   result =  2; break;
    case cards::Rank::Three: result =  3; break;
    case cards::Rank::Four:  result =  4; break;
    case cards::Rank::Five:  result =  5; break;
    case cards::Rank::Six:   result =  6; break;
    case cards::Rank::Seven: result =  7; break;
    case cards::Rank::Eight: result =  8; break;
    case cards::Rank::Nine:  result =  9; break;
    case cards::Rank::Ten:   result =  10; break;
    case cards::Rank::Jack:  result =  10; break;
    case cards::Rank::Queen: result =  10; break;
    case cards::Rank::King:  result =  10; break;
  }
  return result;
}

}

