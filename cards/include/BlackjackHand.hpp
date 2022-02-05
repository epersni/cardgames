#ifndef CARDGAMES_CARDS_BLACKJACKHAND_HPP
#define CARDGAMES_CARDS_BLACKJACKHAND_HPP

#include "BlackjackHandIf.hpp"
#include "HandIf.hpp"

#include <memory>
#include <optional>

//TODO Maybe this is not an library public header?? enough with BlackjackHandIf.hpp

namespace cardgames::cards
{

class BlackjackHand : public BlackjackHandIf
{
public:
  unsigned int GetTotal() const;
  void AddCard(const Card& card) override;
  std::vector<Card> GetCards() const override;
  BlackjackHandIf::Status GetStatus() const override;
private:
  std::vector<Card> mCards;
  std::vector<unsigned int> mValues;

  static unsigned int cardToValue(const Card& card);
};

}

#endif

