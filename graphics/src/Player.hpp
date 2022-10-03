#ifndef CARDGAMES_GRAPHICS_PLAYER_HPP
#define CARDGAMES_GRAPHICS_PLAYER_HPP

#include "Button.hpp"
#include "Node.hpp"
#include "TextFactoryIf.hpp"
#include "TextureFactoryIf.hpp"

#include "config/include/Player.hpp"

#include "../../blackjack/src/game/include/PlayerIf.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace cardgames::graphics
{

class Player : public Node
{
  public:
    Player(const blackjack::game::PlayerIf::Ptr& player,
           const TextureFactoryIf::Ptr& textureFactory,
           const TextFactoryIf::Ptr& textFactory,
           const config::Player& config);
  private:
    blackjack::game::PlayerIf::Ptr mPlayer;
    sf::RectangleShape mHeadUpDisplayBox;
    sf::Text mName;
    sf::Text mCredits;
    //std::vector<Hand::Ptr> mHands; //TODO: needed?
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif

