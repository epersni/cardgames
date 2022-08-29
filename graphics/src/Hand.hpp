#ifndef CARDGAMES_GRAPHICS_HAND_HPP
#define CARDGAMES_GRAPHICS_HAND_HPP

#include "Card.hpp"
#include "Image.hpp"
#include "ImageFactory.hpp"
#include "Node.hpp"

#include "../../blackjack/src/game/include/PlayableHandIf.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <vector>
#include <memory>

namespace cardgames::graphics
{

class Hand : public Node
{
  public:
    using Ptr = std::unique_ptr<Hand>;
    Hand(const blackjack::game::PlayableHandIf::Ptr& playableHand,
         const ImageFactory::Ptr& imageFactory);
    void setPosition(float x, float y);

  private:
    std::vector<Card::Ptr> mCards;
    ImageFactory::Ptr mImageFactory;
    //ChipPile mChipPile; //TODO
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif

