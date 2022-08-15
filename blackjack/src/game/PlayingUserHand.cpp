#include "PlayingUserHand.hpp"
#include "Logging.hpp"

namespace cardgames::blackjack::game{
namespace{
  logging::Logger log = logging::Logger::createLogger("PlayingUserHand");
}

PlayingUserHand::PlayingUserHand(
  const CardProviderIf::Ptr& cardProvider,
  const TimerProviderIf::Ptr& timerProvider,
  const HandControlEnablerIf::Ptr& controlEnabler)
  : mCardProvider(cardProvider)
  , mTimerProvider(timerProvider)
  , mControlEnabler(controlEnabler)
{
}

bool PlayingUserHand::IsPlaying() const
{
  return mIsPlaying;
}

cards::Card PlayingUserHand::Split()
{
  const auto card = mHand.GetCards()[0];
  cards::BlackjackHand newHand;
  newHand.AddCard(card);
  mHand = newHand;
  return card;
}

void PlayingUserHand::Hit()
{
  log.debug("Performing hit");
  mHand.AddCard(mCardProvider->GetCard());
  mIsPlaying = 
    !((mHand.GetStatus() == cards::BlackjackHandIf::Status::Busted) ||
     (mHand.GetStatus() == cards::BlackjackHandIf::Status::BlackJack) ||
     (mHand.GetTotal() == 21));
  updateControls();
  if(!mIsPlaying) 
  {
    log.debug("Done playing, calling callback"); //TODO: not sure about this log
    mCallback();
  }
}

void PlayingUserHand::Double()
{
  mHand.AddCard(mCardProvider->GetCard());
  mIsPlaying = false;
  updateControls();
  mCallback();
}

void PlayingUserHand::Stand()
{
  mIsPlaying = false;
  updateControls();
  mCallback();
}

void PlayingUserHand::updateControls()
{
  log.debug("Updating controls, total={}, playing={}", mHand.GetTotal(), mIsPlaying);
  if(mIsPlaying)
  {
    const auto cards = mHand.GetCards();
    if(cards.size() == 2)
    {
      if(cards[0].rank == cards[1].rank)
      {
        mControlEnabler->EnableActions({HandAction::Stand, HandAction::Hit, 
                                        HandAction::Double, HandAction::Split});
      }
      else
      {
        mControlEnabler->EnableActions({HandAction::Stand, HandAction::Hit, 
                                        HandAction::Double});
      }
    }
    else
    {
      mControlEnabler->EnableActions({HandAction::Stand, HandAction::Hit});
    }
  }
  else
  {
    log.debug("I disabled all controls"); //TODO: not good enough log
    mControlEnabler->EnableActions({});
  }
}

void PlayingUserHand::Play(DonePlayingCb callback)
{
  log.debug("Allowed to play");
  mIsPlaying = true;
  mCallback = callback;
  mTimerProvider->PlayingUserHandTimerCb([this](){ onPlayingTimeExpired(); });
  updateControls();
}

void PlayingUserHand::onPlayingTimeExpired()
{
  log.debug("Playing time expired, done playing calling callback"); //TODO:
  mIsPlaying = false;
  updateControls();
  mCallback();
}

unsigned int PlayingUserHand::GetTotal() const 
{
  return mHand.GetTotal();
}

void PlayingUserHand::ReceiveCard(const cards::Card card)
{
  mHand.AddCard(card);
}

std::vector<cards::Card> PlayingUserHand::GetCards() const
{
  return mHand.GetCards();
}

cards::BlackjackHandIf::Status PlayingUserHand::GetStatus() const
{
  return mHand.GetStatus();
}

}
