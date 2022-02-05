#ifndef CARDGAMES_BLACKJACK_GAME_PLAYING_USER_HAND_HPP
#define CARDGAMES_BLACKJACK_GAME_PLAYING_USER_HAND_HPP

#include "CardProviderIf.hpp"
#include "PlayableHandIf.hpp"
#include "TimerProviderIf.hpp"

#include "../../../cards/include/BlackjackHand.hpp"

namespace cardgames::blackjack::game{

class PlayingUserHand : public PlayableHandIf
{
public:
  PlayingUserHand(const CardProviderIf::Ptr& cardProvider,
                  const TimerProviderIf::Ptr& timerProvider);
  //TODO: controllableHandIf ?
  cards::Card Split();
  void Hit();
  void Double();
  void Stand();

  void Play(DonePlayingCb callback) override; //TODO: maybe this is not part of PlayableHandIf, maybe it is something elseIf?
  unsigned int GetTotal() const override;
  std::vector<cards::Card> GetCards() const override;
  cards::BlackjackHandIf::Status GetStatus() const override;
private:
  const CardProviderIf::Ptr& mCardProvider;
  const TimerProviderIf::Ptr& mTimerProvider;
  cards::BlackjackHand mHand;
};

}

#endif
