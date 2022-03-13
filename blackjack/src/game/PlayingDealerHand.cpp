#include "PlayingDealerHand.hpp"

namespace cardgames::blackjack::game{
namespace
{
  const unsigned int DEALER_HITS_ON_LIMIT = 17;
}

PlayingDealerHand::PlayingDealerHand(const CardProviderIf::Ptr& cardProvider,
                                     const TimerProviderIf::Ptr& timerProvider)
  : mCardProvider(cardProvider)
  , mTimerProvider(timerProvider)
{
}

void PlayingDealerHand::Play(DonePlayingCb callback)
{
  if(mHand.GetTotal() < DEALER_HITS_ON_LIMIT)
  {
    mIsPlaying = true;
    mDonePlayingCallback = callback;
    mTimerProvider->DealerDecisionTimerCb([this]()
        { 
          this->onDealerDecisionTimeOut(); 
        });
  }
  else
  {
    mIsPlaying = false;
    callback();
  }
}

bool PlayingDealerHand::IsPlaying() const 
{
  return mIsPlaying;
}

void PlayingDealerHand::ReceiveCard(const cards::Card card)
{
  mHand.AddCard(card);
}

unsigned int PlayingDealerHand::GetTotal() const 
{
  return mHand.GetTotal();
}

std::vector<cards::Card> PlayingDealerHand::GetCards() const 
{
  return mHand.GetCards();
}

cards::BlackjackHandIf::Status PlayingDealerHand::GetStatus() const 
{
  return mHand.GetStatus();
}

void PlayingDealerHand::onDealerDecisionTimeOut()
{
  mHand.AddCard(mCardProvider->GetCard());
  Play(mDonePlayingCallback);
}

}
