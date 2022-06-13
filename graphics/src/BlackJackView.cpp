#include "BlackJackView.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

namespace cardgames::graphics
{

BlackJackView::BlackJackView(int width, int height)
  : mWindow(sf::VideoMode(width, height), "BlackJack")
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
  //TODO: do not have this shape...
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  mWindow.clear();
  mWindow.draw(shape);
  mWindow.display();
}



}
