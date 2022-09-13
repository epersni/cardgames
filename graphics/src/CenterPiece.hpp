#ifndef CARDGAMES_GRAPHICS_CENTERPIECE_HPP
#define CARDGAMES_GRAPHICS_CENTERPIECE_HPP

#include "Node.hpp"
#include "TextFactoryIf.hpp"

#include <SFML/Graphics/Text.hpp>

namespace cardgames::graphics
{

class CenterPiece : public Node
{
  public:
    CenterPiece(const TextFactoryIf::Ptr& textFactory);
  private:
    sf::Text mTitle;
    sf::Text mRow1;
    sf::Text mRow2;
    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}

#endif


