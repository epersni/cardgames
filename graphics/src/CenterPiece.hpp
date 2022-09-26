#ifndef CARDGAMES_GRAPHICS_CENTERPIECE_HPP
#define CARDGAMES_GRAPHICS_CENTERPIECE_HPP

#include "Node.hpp"
#include "TextFactoryIf.hpp"

#include "config/include/Centerpiece.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace cardgames::graphics
{

class CenterPiece : public Node
{
  public:
    CenterPiece(
        const config::Centerpiece& config,
        const TextFactoryIf::Ptr& textFactory);
  private:
    sf::Text mTitle;
    sf::Text mRow1;
    sf::Text mRow2;
    sf::CircleShape mCircle;
    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}

#endif


