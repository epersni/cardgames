#ifndef CARDGAMES_GRAPHICS_VIEW_FACTORY_HPP
#define CARDGAMES_GRAPHICS_VIEW_FACTORY_HPP

#include "ViewIf.hpp"
#include "../../blackjack/src/game/include/PlayerIf.hpp"
#include "../../blackjack/src/game/include/PlayableHandIf.hpp"

namespace cardgames::graphics
{

class ViewFactory
{
public:
  ViewIf::Ptr CreateBlackJackView(int width, 
                                  int height,
                                  cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
                                  std::vector<cardgames::blackjack::game::PlayerIf::Ptr> players) const;
};

}

#endif


