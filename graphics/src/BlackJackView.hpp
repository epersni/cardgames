#ifndef CARDGAMES_GRAPHICS_BLACKJACK_VIEW_HPP
#define CARDGAMES_GRAPHICS_BLACKJACK_VIEW_HPP

#include "ImageFactoryIf.hpp"
#include "ViewIf.hpp"

#include <SFML/Graphics.hpp>

namespace cardgames::graphics
{

class BlackJackView : public ViewIf
{
public:
  BlackJackView(int width, int height, ImageFactoryIf::Ptr imageFactory);
  bool IsWindowOpen() const override;
  bool PollEvent(sf::Event& event) override;
  void CloseWindow() override;
  void Render() override;

private:
  sf::RenderWindow mWindow;
  Image mBackground;
};


}

#endif
