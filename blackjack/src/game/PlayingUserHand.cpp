#include "PlayingUserHand.hpp"

namespace cardgames::blackjack::game{

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
  mHand.AddCard(mCardProvider->GetCard());
  mIsPlaying = mHand.GetStatus() != cards::BlackjackHandIf::Status::Busted;
  updateControls();
  mCallback();
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
      mControlEnabler->EnableActions({HandAction::Stand});
    }
  }
  else
  {
    mControlEnabler->EnableActions({});
  }
}

void PlayingUserHand::Play(DonePlayingCb callback)
{
  mIsPlaying = true;
  mCallback = callback;
  mTimerProvider->PlayingUserHandTimerCb([this](){ onPlayingTimeExpired(); });
  updateControls();
}

void PlayingUserHand::onPlayingTimeExpired()
{
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
