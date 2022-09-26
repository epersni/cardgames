#ifndef CARDGAMES_GRAPHICS_BLACKJACK_VIEW_HPP
#define CARDGAMES_GRAPHICS_BLACKJACK_VIEW_HPP

#include "Player.hpp"
#include "CenterPiece.hpp"
#include "TextFactoryIf.hpp"
#include "TextureFactoryIf.hpp"
#include "ViewIf.hpp"

#include "config/include/BlackjackConfig.hpp"

#include "../../blackjack/src/game/include/PlayerIf.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

namespace cardgames::graphics
{

class BlackJackView : public ViewIf
{
public:
  BlackJackView(cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
                const std::vector<cardgames::blackjack::game::PlayerIf::Ptr>& players,
                const config::Blackjack&& config,
                TextureFactoryIf::Ptr textureFactory,
                TextFactoryIf::Ptr textFactory);
  bool IsWindowOpen() const override;
  bool PollEvent(sf::Event& event) override;
  void CloseWindow() override;
  void Render() override;
  void Update(uint32_t timeMs) override;

private:
  const config::Blackjack mConfig;
  sf::RenderWindow mWindow;
  sf::Sprite mBackground;
  TextureFactoryIf::Ptr mTextureFactory;
  TextFactoryIf::Ptr mTextFactory;
  CenterPiece mCenterPiece;
  cardgames::blackjack::game::PlayableHandIf::Ptr mDealerHand;
  std::vector<cardgames::blackjack::game::PlayerIf::Ptr> mPlayers;
};


}

#endif
