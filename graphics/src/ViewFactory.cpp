#include "ViewFactory.hpp"
#include "TextureFactory.hpp"
#include "TextFactory.hpp"
#include "BlackJackView.hpp"

namespace cardgames::graphics
{

ViewIf::Ptr ViewFactory::CreateBlackJackView(
    int width, 
    int height, 
    cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
    std::vector<cardgames::blackjack::game::PlayerIf::Ptr> players) const
{
  return std::make_shared<BlackJackView>(
      width, 
      height, 
      dealerHand,
      players,
      std::make_shared<TextureFactory>("/home/nicklas/src/cardgames/graphics/images/"),
      std::make_shared<TextFactory>("/home/nicklas/src/cardgames/graphics/fonts/"));
}
}

