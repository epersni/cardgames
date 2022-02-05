#ifndef CARDGAMES_BLACKJACK_GAME_OUTCOME_FACTORY_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_OUTCOME_FACTORY_IF_HPP

#include "PlayableHandIf.hpp"
#include "Outcome.hpp"

#include <memory>

namespace cardgames::blackjack::game{

struct OutcomeFactoryIf
{
  virtual Outcome CreateOutcome(const std::shared_ptr<PlayableHandIf>& player,
                                const std::shared_ptr<PlayableHandIf>& dealer) = 0;
};

}

#endif


