#include "../include/Card.hpp"

#include <vector>

namespace cardgames::cards
{
  bool operator==(const Card& lhs, const Card& rhs)
  {
    return (lhs.suit == rhs.suit) && (lhs.rank == rhs.rank);
  }
}

