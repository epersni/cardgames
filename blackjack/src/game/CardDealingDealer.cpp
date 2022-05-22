#include "CardDealingDealer.hpp"
#include "Logging.hpp"
#include <algorithm>

namespace cardgames::blackjack::game{
namespace
{
  auto log = logging::Logger::createLogger("CardDealingDealer");
}

CardDealingDealer::CardDealingDealer(const CardProviderIf::Ptr& cardProvider)
  : mCardProvider(cardProvider)
{
}

void CardDealingDealer::JoinNextDealingRound(CardReceiverIf::Ptr cardReceiver)
{
  mCardReceivers.push_back(cardReceiver);
}

void CardDealingDealer::DealCards(CardsDealtCb callback)
{
  log.info("Dealing cards");
  auto dealIteration = [this](CardReceiverIf::Ptr receiver)
  {
    receiver->ReceiveCard(std::move(mCardProvider->GetCard()));
  };
  std::for_each(mCardReceivers.begin(), mCardReceivers.end(), dealIteration);
  std::for_each(mCardReceivers.begin(), mCardReceivers.end(), dealIteration);
  callback();
}

cards::Card CardDealingDealer::GetCard()
{
  log.trace("Pull one card from provider");
  return mCardProvider->GetCard();
}
  
}
