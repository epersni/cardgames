#include "PlayingUserHand.hpp"

namespace cardgames::blackjack::game{

PlayingUserHand::PlayingUserHand(const CardProviderIf::Ptr& cardProvider,
                                 const TimerProviderIf::Ptr& timerProvider)
  : mCardProvider(cardProvider)
  , mTimerProvider(timerProvider)
{
}

cards::Card PlayingUserHand::Split()
{
  // Remote a card, return that card
  // tell some controls what actions are available from now on: depends?
}

void PlayingUserHand::Hit()
{
}

void PlayingUserHand::Double()
{
  //take a card
  // tell some controls what actions are available from now on: none
}

void PlayingUserHand::Stand()
{
  // call mDoneCallback
  // tell some controls what actions are available from now on: none
}

void PlayingUserHand::Play(DonePlayingCb callback)
{
  //save callback
  // tell some controls what actions are available from now on
}

unsigned int PlayingUserHand::GetTotal() const 
{
  return mHand.GetTotal();
}

std::vector<cards::Card> PlayingUserHand::GetCards() const
{
}

cards::BlackjackHandIf::Status PlayingUserHand::GetStatus() const
{
  return mHand.GetStatus();
}

}
