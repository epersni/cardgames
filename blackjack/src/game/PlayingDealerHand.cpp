#include "PlayingDealerHand.hpp"
#include "Logging.hpp"

namespace cardgames::blackjack::game{
namespace
{
  auto log = logging::Logger::createLogger("PlayingDealerHand");
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
  mIsPlaying = true;
  mDonePlayingCallback = callback;
  mTimerProvider->
    DealerDecisionTimerCb([this](){ DoNextMove(); });
}

void PlayingDealerHand::DoNextMove()
{
  if(mHand.GetTotal() < DEALER_HITS_ON_LIMIT)
  {
    log.info("Dealer total={} is still under limit({}), will hit once more",
             mHand.GetTotal(), DEALER_HITS_ON_LIMIT);
    mHand.AddCard(mCardProvider->GetCard());
    mTimerProvider->
      DealerDecisionTimerCb([this](){ DoNextMove(); });
  }
  else
  {
    log.info("Dealer is done playing, total={}", mHand.GetTotal());
    mIsPlaying = false;
    mDonePlayingCallback();
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
}

}
