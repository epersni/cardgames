#ifndef CARDGAMES_GRAPHICS_CARD_HPP
#define CARDGAMES_GRAPHICS_CARD_HPP

#include "Image.hpp"
#include "ImageFactory.hpp"
#include "Node.hpp"

#include "../../cards/include/Card.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>

namespace cardgames::graphics
{

class Card : public Node
{
  public:
    using Ptr = std::shared_ptr<Card>;
    Card(const cards::Card card,
         const ImageFactory::Ptr& imageFactory);
    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const final;

  private:
    Image mImage;
};

}

#endif



