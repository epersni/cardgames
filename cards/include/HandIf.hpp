#ifndef CARDGAMES_CARDS_HAND_IF_HPP
#define CARDGAMES_CARDS_HAND_IF_HPP

#include "Card.hpp"

#include <memory>
#include <vector>

namespace cardgames::cards
{

struct HandIf //TODO: meant for readonly, maybe rename
{
//  virtual void AddCard(const Card& card) = 0;
  using Ptr = std::shared_ptr<HandIf>;
  virtual std::vector<Card> GetCards() const = 0;
};

}

#endif
