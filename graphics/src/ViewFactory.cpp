#include "ViewFactory.hpp"
#include "ImageFactory.hpp"
#include "TextFactory.hpp"
#include "BlackJackView.hpp"

namespace cardgames::graphics
{

ViewIf::Ptr ViewFactory::CreateBlackJackView(
    int width, 
    int height, 
    std::vector<cardgames::blackjack::game::PlayerIf::Ptr> players) const
{
  return std::make_shared<BlackJackView>(
      width, 
      height, 
      players,
      std::make_shared<ImageFactory>("/home/nicklas/src/cardgames/graphics/images"),
      std::make_shared<TextFactory>("/home/nicklas/src/cardgames/graphics/fonts"));
}
}

