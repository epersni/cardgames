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
  keyEventPublisher->subscribeToKeyPressed(userButton1, [&](){ HandleButton1(); });
  keyEventPublisher->subscribeToKeyPressed(userButton2, [&](){ HandleButton2(); });
  keyEventPublisher->subscribeToKeyPressed(userButton3, [&](){ HandleButton1(); });
  keyEventPublisher->subscribeToKeyPressed(userButton4, [&](){ HandleButton4(); });
}

void PlayerController::HandleButton1()
{
  log.debug("HandleButton1");
  if(mButton1Cb)
  {
  log.debug("mButton1Cb was not nullptr");
    mButton1Cb();
    //mButton1Cb = nullptr;
  }
}

void PlayerController::HandleButton2()
{
  if(mButton2Cb)
  {
    mButton2Cb();
    mButton2Cb = nullptr;
  }
}

void PlayerController::HandleButton3()
{
  if(mButton3Cb)
  {
    mButton3Cb();
    mButton3Cb = nullptr;
  }
}

void PlayerController::HandleButton4()
{
  if(mButton4Cb)
  {
    mButton4Cb();
    mButton4Cb = nullptr;
  }
}
 
//TODO: Note to self. We need to have two separate instances of this
//      class. So calling DisableAll() is safe from the other object.

void PlayerController::DisableAll()
{
  mButton1Cb = nullptr;
  mButton2Cb = nullptr;
  mButton3Cb = nullptr;
  mButton4Cb = nullptr;
  log.debug("All controls are now disabled");
}

void PlayerController::OnStand(std::function<void()> cb)
{
  mButton4Cb = cb;
}

void PlayerController::OnSplit(std::function<void()> cb)
{
  mButton2Cb = cb;
}

void PlayerController::OnDouble(std::function<void()> cb)
{
  mButton3Cb = cb;
}

void PlayerController::OnHit(std::function<void()> cb)
{
  log.debug("Enabling OnHit control"); //TODO not sure about this log
  mButton1Cb = cb;
}

void PlayerController::OnPlaceBet(std::function<void()> cb)
{
  log.debug("Enabling OnPlaceBet control"); //TODO not sure about this log
  mButton1Cb = cb;
}

}

