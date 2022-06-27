#include "BlackJackView.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

namespace cardgames::graphics
{

BlackJackView::BlackJackView(
    int width, 
    int height, 
    std::vector<cardgames::blackjack::game::PlayerIf::Ptr> players,
    ImageFactoryIf::Ptr imageFactory)
  : mWindow(sf::VideoMode(width, height), "BlackJack")
  , mBackground(imageFactory->CreateImage("background_2560x1440.png"))
{
  for(auto& player : players)
  {
    mPlayers.push_back({player});
  }
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
  std::for_each(mPlayers.begin(), 
                mPlayers.end(),
                [&](auto player){ mWindow.draw(player); });
  //mWindow.draw(m
  mWindow.display();
}



}
