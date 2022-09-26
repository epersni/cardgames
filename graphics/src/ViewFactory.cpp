#include "ViewFactory.hpp"
#include "TextureFactory.hpp"
#include "TextFactory.hpp"
#include "BlackJackView.hpp"

#include "config/include/BlackjackConfig.hpp"

namespace cardgames::graphics
{

ViewIf::Ptr ViewFactory::CreateBlackJackView(
    cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
    std::vector<cardgames::blackjack::game::PlayerIf::Ptr> players,
    std::filesystem::path config) const
{
  config::BlackjackConfig blackjackConfig(config);

  return std::make_shared<BlackJackView>(
      dealerHand,
      players,
      std::move(blackjackConfig.GetConfig()),
      std::make_shared<TextureFactory>("/home/nicklas/src/cardgames/graphics/images/"),
      std::make_shared<TextFactory>("/home/nicklas/src/cardgames/graphics/fonts/"));
}
}

