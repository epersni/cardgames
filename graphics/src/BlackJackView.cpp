#include "BlackJackView.hpp"

#include <SFML/Graphics.hpp>

namespace cardgames::graphics
{

BlackJackView::BlackJackView(
    int width, 
    int height, 
    cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
    const std::vector<cardgames::blackjack::game::PlayerIf::Ptr>& players,
    TextureFactoryIf::Ptr textureFactory,
    TextFactoryIf::Ptr textFactory)
  : mWindow(sf::VideoMode(width, height), "BlackJack")
  , mBackground(textureFactory->Load("background_2560x1440.png")) //TODO: do not hardcode resolution in imagepath
  , mTextureFactory(textureFactory)
  , mTextFactory(textFactory)
  , mDealerHand(dealerHand)
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

void BlackJackView::Update(const uint32_t timeMs)
{
  //TODO:
}

void BlackJackView::Render()
{
  mWindow.clear();
  mWindow.draw(mBackground);
  unsigned int playerOffset = 0; 
  
  auto dealerHand = Hand(mDealerHand, mTextureFactory, mTextFactory);
  dealerHand.setPosition(500, 500); //TODO configurable
  mWindow.draw(dealerHand); 

  for(auto& player : mPlayers)
  {
    auto p = Player(player, mTextureFactory, mTextFactory);
    p.setPosition(0+playerOffset, 0+playerOffset);//TODO: magic number for now, no support (yet) for split hands anyway
    mWindow.draw(p); 
  }

  mWindow.display();
}



}
