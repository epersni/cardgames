#ifndef CARDGAMES_BLACKJACK_GAME_PLAYER_CONTROLLER_IF_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYER_CONTROLLER_IF_HPP

#include "BettingControlsIf.hpp"
#include "PlayingControlsIf.hpp"

#include "KeyEventPublisher.hpp"

namespace cardgames::blackjack::game{

class PlayerController 
  : public BettingControlsIf
  , public PlayingControlsIf
{
public:
  PlayerController(cardgames::common::KeyEventPublisher::Ptr keyEventPublisher,
                   cardgames::common::KeyEventPublisher::Key userButton1,
                   cardgames::common::KeyEventPublisher::Key userButton2,
                   cardgames::common::KeyEventPublisher::Key userButton3,
                   cardgames::common::KeyEventPublisher::Key userButton4);
  
  void HandleButton1();
  void HandleButton2();
  void HandleButton3();
  void HandleButton4();

  void OnPlaceBet(std::function<void()> cb) override;

  void OnStand(std::function<void()> cb) override;
  void OnSplit(std::function<void()> cb) override;
  void OnDouble(std::function<void()> cb) override;
  void OnHit(std::function<void()> cb) override;

  void DisableAll() override;

private:
  ButtonPressedCb mButton1Cb;
  ButtonPressedCb mButton2Cb;
  ButtonPressedCb mButton3Cb;
  ButtonPressedCb mButton4Cb;
};

}

#endif

