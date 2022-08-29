#include "BlackJackView.hpp"

#include <SFML/Graphics.hpp>

#include <iostream> //TODO

namespace cardgames::graphics
{

BlackJackView::BlackJackView(
    int width, 
    int height, 
    const std::vector<cardgames::blackjack::game::PlayerIf::Ptr>& players,
    ImageFactoryIf::Ptr imageFactory)
  : mWindow(sf::VideoMode(width, height), "BlackJack")
  , mBackground(imageFactory->CreateImage("background_2560x1440.png")) //TODO: do not hardcode resolution in imagepath
  , mImageFactory(imageFactory)
  , mPlayers(players)
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
  unsigned int playerOffset = 0; 
  for(auto& player : mPlayers)
  {
    auto p = Player(player, mImageFactory);//TODO: why did I have to recreate players??
    p.setPosition(0+playerOffset, 0+playerOffset);//TODO: magic number for now, no support (yet) for split hands anyway
    mWindow.draw(p); 
  }

  mWindow.display();
}



}
