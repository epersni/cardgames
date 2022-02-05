#ifndef CARDGAMES_BLACKJACK_GAME_PLAYING_DEALER_HAND_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYING_DEALER_HAND_HPP

#include "CardProviderIf.hpp"
#include "CardReceiverIf.hpp"
#include "PlayableHandIf.hpp"
#include "TimerProviderIf.hpp"

#include "../../../cards/include/BlackjackHand.hpp"

#include <vector>

namespace cardgames::blackjack::game{

class PlayingDealerHand
  : public PlayableHandIf
  , public CardReceiverIf
{
public:
  PlayingDealerHand(const CardProviderIf::Ptr& cardProvider,
                    const TimerProviderIf::Ptr& timerProvider);
  void Play(DonePlayingCb callback);
  void ReceiveCard(const cards::Card card);
  unsigned int GetTotal() const override; //TODO unit test this
  std::vector<cards::Card> GetCards() const override; //TODO unit test this
  cards::BlackjackHandIf::Status GetStatus() const override; //TODO unit test this

private:
  const CardProviderIf::Ptr& mCardProvider;
  const TimerProviderIf::Ptr& mTimerProvider;
  cards::BlackjackHand mHand;
  DonePlayingCb mDonePlayingCallback; 
  void onDealerDecisionTimeOut();
};

}

#endif




