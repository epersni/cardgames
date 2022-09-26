#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_BLACKJACK_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_BLACKJACK_HPP

#include "Image.hpp"
#include "Centerpiece.hpp"
#include "Hand.hpp"
#include "Player.hpp"
#include "Window.hpp"

namespace cardgames::graphics::config
{

struct Blackjack
{
  Window window;
  Centerpiece centerpiece;
  Image background;
  Hand dealerHand;
  Player players[4];
};

}

#endif
