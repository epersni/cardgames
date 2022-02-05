#ifndef CARDGAMES_BLACKJACK_GAME_CARD_PROVIDER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_CARD_PROVIDER_IF_HPP

#include "../../../cards/include/Card.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct CardProviderIf
{
  using Ptr = std::shared_ptr<CardProviderIf>;
  virtual cards::Card GetCard() = 0;
};

}

#endif



