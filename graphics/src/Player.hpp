#ifndef CARDGAMES_GRAPHICS_PLAYER_HPP
#define CARDGAMES_GRAPHICS_PLAYER_HPP

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

class Player : public Node
{
  public:
    Player(const blackjack::game::PlayerIf::Ptr& player,
           const ImageFactory::Ptr& imageFactory,
           const TextFactory::Ptr& textFactory);
  private:
    blackjack::game::PlayerIf::Ptr mPlayer;
    std::vector<Hand::Ptr> mHands;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif

