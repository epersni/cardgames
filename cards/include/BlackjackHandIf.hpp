#ifndef CARDGAMES_CARDS_BLACKJACK_HAND_IF_HPP
#define CARDGAMES_CARDS_BLACKJACK_HAND_IF_HPP

#include "Card.hpp"
#include "HandIf.hpp"

#include <memory>
#include <vector>

namespace cardgames::cards
{

struct BlackjackHandIf : HandIf
{
  enum class Status
  {
    Numeric,
    Busted,
    BlackJack
  };
  using Ptr = std::shared_ptr<BlackjackHandIf>;
  virtual void AddCard(const Card& card) = 0;
  virtual unsigned int GetTotal() const = 0;
  virtual Status GetStatus() const = 0;
};

}

#endif

