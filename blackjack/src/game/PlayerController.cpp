#include "PlayerController.hpp"
#include "Logging.hpp"

using namespace cardgames::common;

namespace cardgames::blackjack::game{
namespace
{
  auto log = logging::Logger::createLogger("PlayerController");
}

PlayerController::PlayerController(
    cardgames::common::KeyEventPublisher::Ptr keyEventPublisher,
    cardgames::common::KeyEventPublisher::Key userButton1,
    cardgames::common::KeyEventPublisher::Key userButton2,
    cardgames::common::KeyEventPublisher::Key userButton3,
    cardgames::common::KeyEventPublisher::Key userButton4)
{
  keyEventPublisher->subscribeToKeyPressed(
      userButton1,
      [&](){ 
        if(mPlaceBetCb)
        { 
          log.debug("Userbutton1 pressed, calling callback for 'PlaceBet'");
          mPlaceBetCb(10); //TODO: how to know how much to bet per bet?
          mPlaceBetCb = nullptr;
        }
        if(mStandCb)
        { 
          log.debug("Userbutton1 pressed, calling callback for 'Stand'");
          mStandCb();
          mStandCb = nullptr;
        }});
  keyEventPublisher->subscribeToKeyPressed(
      userButton2,
      [&](){ 
        if(mSplitCb)
        {
          log.debug("Userbutton2 pressed, calling callback for 'Split'");
          mSplitCb();
          mSplitCb = nullptr;
        }});
  
  keyEventPublisher->subscribeToKeyPressed(
      userButton3,
      [&](){ 
        if(mDoubleCb)
        {
          log.debug("Userbutton3 pressed, calling callback for 'Double'");
          mDoubleCb(); 
          mDoubleCb = nullptr;
        }});
 
  keyEventPublisher->subscribeToKeyPressed(
      userButton4,
      [&](){ 
        if(mHitCb)
        {
          log.debug("Userbutton3 pressed, calling callback for 'Hit'");
          mHitCb();
          mHitCb = nullptr;
        }});
}
  
void PlayerController::DisableAll()
{
  mPlaceBetCb = nullptr;
  mStandCb = nullptr;
  mSplitCb = nullptr;
  mDoubleCb = nullptr;
  mHitCb = nullptr;
  log.debug("All controls are now disabled");
}

void PlayerController::OnStand(std::function<void()> cb)
{
  mStandCb = cb;
}

void PlayerController::OnSplit(std::function<void()> cb)
{
  mSplitCb = cb;
}

void PlayerController::OnDouble(std::function<void()> cb)
{
  mDoubleCb = cb;
}

void PlayerController::OnHit(std::function<void()> cb)
{
  mHitCb = cb;
}

void PlayerController::OnPlaceBet(OnBetsPlacedCb cb)
{
  mPlaceBetCb = cb;
}

}

