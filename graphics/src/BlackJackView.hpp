#ifndef CARDGAMES_GRAPHICS_BLACKJACK_VIEW_HPP
#define CARDGAMES_GRAPHICS_BLACKJACK_VIEW_HPP

#include "ImageFactoryIf.hpp"
#include "Player.hpp"
#include "ViewIf.hpp"

#include "../../blackjack/src/game/include/PlayerIf.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

namespace cardgames::graphics
{

class BlackJackView : public ViewIf
{
public:
  BlackJackView(int width,
                int height, 
                const std::vector<cardgames::blackjack::game::PlayerIf::Ptr>& players,
                ImageFactoryIf::Ptr imageFactory);
  bool IsWindowOpen() const override;
  bool PollEvent(sf::Event& event) override;
  void CloseWindow() override;
  void Render() override;

private:
  sf::RenderWindow mWindow;
  Image mBackground;
  ImageFactory::Ptr mImageFactory;
  std::vector<cardgames::blackjack::game::PlayerIf::Ptr> mPlayers;
};


}

#endif
