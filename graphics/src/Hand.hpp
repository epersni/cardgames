#ifndef CARDGAMES_GRAPHICS_HAND_HPP
#define CARDGAMES_GRAPHICS_HAND_HPP

#include "Card.hpp"
#include "TextureFactoryIf.hpp"
#include "TextFactory.hpp"
#include "Node.hpp"

#include "../../blackjack/src/game/include/PlayableHandIf.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
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
         const TextureFactoryIf::Ptr& textureFactory,
         const TextFactory::Ptr& textFactory);

  private:
    const blackjack::game::PlayableHandIf::Ptr mHand;
    std::vector<Card::Ptr> mCards;
    sf::Text mSumText;
    //ChipPile mChipPile; //TODO
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif

