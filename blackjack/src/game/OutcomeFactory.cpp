#include "OutcomeFactory.hpp"

namespace cardgames::blackjack::game{

Outcome OutcomeFactory::CreateOutcome(const std::shared_ptr<PlayableHandIf>& player,
                                      const std::shared_ptr<PlayableHandIf>& dealer)
{
  const auto dealerStatus = dealer->GetStatus();
  const auto playerStatus = player->GetStatus();
  
  if(playerStatus == cards::BlackjackHandIf::Status::Busted)
  {
    return Outcome::Lose;
  }
  else if((playerStatus == cards::BlackjackHandIf::Status::BlackJack) &&
          (dealerStatus != cards::BlackjackHandIf::Status::BlackJack))
  {
    return Outcome::BlackJack;
  }
  else if((player->GetStatus() == cards::BlackjackHandIf::Status::Numeric) &&
          (dealer->GetStatus() == cards::BlackjackHandIf::Status::Busted))
  {
    return Outcome::Win;
  }
  else if((playerStatus == cards::BlackjackHandIf::Status::Numeric) &&
          (dealerStatus == cards::BlackjackHandIf::Status::Numeric) &&
          (player->GetTotal() > dealer->GetTotal()))
  {
    return Outcome::Win;
  }
  else if((player->GetTotal() == dealer->GetTotal()) && 
          (dealerStatus == cards::BlackjackHandIf::Status::Numeric) &&
          (playerStatus == cards::BlackjackHandIf::Status::Numeric))
  {
    return Outcome::Draw;
  }
  //TODO: assert here? At least critical log!
  return Outcome::Lose;
}


}

