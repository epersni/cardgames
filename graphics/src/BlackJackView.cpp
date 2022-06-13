#include "BlackJackView.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

namespace cardgames::graphics
{

BlackJackView::BlackJackView(
    int width, int height, ImageFactoryIf::Ptr imageFactory)
  : mWindow(sf::VideoMode(width, height), "BlackJack")
  , mBackground(imageFactory->CreateImage("background_2560x1440.png"))
{
}

bool BlackJackView::IsWindowOpen() const
{
  return mWindow.isOpen();
}

bool BlackJackView::PollEvent(sf::Event& event)
{
  return mWindow.pollEvent(event);
}

void BlackJackView::CloseWindow()
{
  mWindow.close();
}

void BlackJackView::Render()
{
  mWindow.clear();
  mWindow.draw(mBackground);
  mWindow.display();
}



}
