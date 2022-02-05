#ifndef CARDGRAPHICS_VIEW_HPP
#define CARDGRAPHICS_VIEW_HPP

#include "Hand.hpp"
#include "Image.hpp"

//#include "../KeyEventPublisher.hpp"

#include <SFML/Graphics/Drawable.hpp>

namespace cardgames::graphics
{

class View : public sf::Drawable
{
  public:
    View();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  private:
    //KeyEventPublisher::Ptr mKeyEventPublisher;
    Image mBackground;
    Hand mDealerHand;

    void onKeyPressed();
//    std::vector<PlayerView> mPlayerHands;
//    InstructionLabel mInstructions;
};


}

#endif
