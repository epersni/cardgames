#ifndef CARDGAMES_BLACKJACK_GAME_PLAYING_USER_HAND_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYING_USER_HAND_HPP

#include "CardProviderIf.hpp"
#include "CardReceiverIf.hpp"
#include "HandControlEnablerIf.hpp"
#include "PlayableHandIf.hpp"
#include "TimerProviderIf.hpp"

#include "../../../cards/include/BlackjackHand.hpp"

namespace cardgames::blackjack::game{

class PlayingUserHand 
  : public PlayableHandIf
  , public CardReceiverIf
{
public:
  PlayingUserHand(const CardProviderIf::Ptr& cardProvider,
                  const TimerProviderIf::Ptr& timerProvider,
                  const HandControlEnablerIf::Ptr& controlEnabler);
  
  cards::Card Split();
  void Hit();
  void Double();
  void Stand();

  void Play(DonePlayingCb callback) override;
  bool IsPlaying() const override;
  unsigned int GetTotal() const override;
  std::vector<cards::Card> GetCards() const override;
  cards::BlackjackHandIf::Status GetStatus() const override;

  void ReceiveCard(const cards::Card card) override;
private:
  const CardProviderIf::Ptr& mCardProvider;
  const TimerProviderIf::Ptr& mTimerProvider;
  const HandControlEnablerIf::Ptr& mControlEnabler;
  cards::BlackjackHand mHand;
  bool mIsPlaying = false;
  DonePlayingCb mCallback;

  void updateControls();
  void onPlayingTimeExpired();
};

}

#endif
