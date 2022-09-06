#ifndef CARDGAMES_GRAPHICS_DEALER_HPP
#define CARDGAMES_GRAPHICS_DEALER_HPP

#include "Hand.hpp"
#include "ImageFactoryIf.hpp"
#include "Node.hpp"
#include "TextFactoryIf.hpp"

#include "../../blackjack/src/game/include/PlayerIf.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace cardgames::graphics
{

class Dealer : public Node
{
  public:
    Dealer(const cardgames::blackjack::game::PlayableHandIf::Ptr& dealerHand,
           const ImageFactory::Ptr& imageFactory,
           const TextFactory::Ptr& textFactory);
  private:
    Hand mHand;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif


