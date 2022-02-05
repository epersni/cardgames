#ifndef CARDGAMES_GRAPHICS_HAND_HPP
#define CARDGAMES_GRAPHICS_HAND_HPP

#include "Image.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <vector>
#include <memory>

namespace cardgames::graphics
{

class Hand : public sf::Drawable
{
  public:
    void addCard(/*cards::Card card*/);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    void setPosition(float x, float y);

  private:
    std::vector<std::shared_ptr<Image>> mCards;
    //ChipPile mChipPile;
};

}

#endif

