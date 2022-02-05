#ifndef CARDGAMES_BLACKJACK_GAME_OUTCOME_FACTORY_HPP
#define CARDGAMES_BLACKJACK_GAME_OUTCOME_FACTORY_HPP

#include "OutcomeFactoryIf.hpp"

namespace cardgames::blackjack::game{

class OutcomeFactory : public OutcomeFactoryIf
{
public:
  Outcome CreateOutcome(const std::shared_ptr<PlayableHandIf>& player,
                        const std::shared_ptr<PlayableHandIf>& dealer);
};

}

#endif



