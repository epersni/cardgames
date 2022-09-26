#include "BlackJackView.hpp"

#include <SFML/Graphics.hpp>

namespace cardgames::graphics
{

BlackJackView::BlackJackView(
    cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
    const std::vector<cardgames::blackjack::game::PlayerIf::Ptr>& players,
    const config::Blackjack&& config,
    TextureFactoryIf::Ptr textureFactory,
    TextFactoryIf::Ptr textFactory)
  : mConfig(config)
  , mWindow(sf::VideoMode(config.window.width, config.window.height), config.window.title)
  , mBackground(textureFactory->Load("background_2560x1440.png")) //TODO: do not hardcode resolution in imagepath
  , mTextureFactory(textureFactory)
  , mTextFactory(textFactory)
  , mCenterPiece(config.centerpiece, textFactory)
  , mDealerHand(dealerHand)
  , mPlayers(players)
{
  //mCenterPiece.setPosition(width/2.0f, height/2.0f); //TODO: automaticall at center even if resize
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
  mWindow.draw(mCenterPiece);
  unsigned int playerOffset = 0; 
  
  auto dealerHand = Hand(mDealerHand,
                         mTextureFactory,
                         mTextFactory,
                         mConfig.dealerHand);
  mWindow.draw(dealerHand); 

  //for(auto& player : mPlayers)
  //{
    auto p = Player(mPlayers[0], mTextureFactory, mTextFactory, mConfig.players[0]);
    mWindow.draw(p); 
  //}

  mWindow.display();
}



}
