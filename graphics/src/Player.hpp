#ifndef CARDGAMES_GRAPHICS_PLAYER_HPP
#define CARDGAMES_GRAPHICS_PLAYER_HPP

#include "Hand.hpp"

#include "../../blackjack/src/game/include/PlayerIf.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace cardgames::graphics
{

class Player : public sf::Drawable
{
  public:
    Player(const blackjack::game::PlayerIf::Ptr& player);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    void setPosition(float x, float y);

  private:
    blackjack::game::PlayerIf::Ptr mPlayer;
    //std::vector<Hand> mHands;
    //ChipPile mChipPile;
};

}

#endif


