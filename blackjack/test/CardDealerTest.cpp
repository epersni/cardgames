#include "CardDealingDealer.hpp"
#include "DeckIf.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::cards;
using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct CardDealerTest
{
  CardDealerTest()
    : mockedCardReceivers(4)
    , cardReceivers{MockPtr(CardReceiverIf, mockedCardReceivers[0]),
                    MockPtr(CardReceiverIf, mockedCardReceivers[1]),
                    MockPtr(CardReceiverIf, mockedCardReceivers[2]),
                    MockPtr(CardReceiverIf, mockedCardReceivers[3])}
    , deck(MockPtr(DeckIf, mockedDeck))
    , dealer(deck, cardReceivers)
  {
    for(auto& r : mockedCardReceivers)
    {
      Fake(Method(r,ReceiveCard)); 
    }
    Fake(Method(mockedDeck, Draw));
    Fake(Method(mockedDeck, Shuffle));
    When(Method(mockedDeck, CardsLeft)).AlwaysReturn(52);
  }
  std::vector<Mock<CardReceiverIf>> mockedCardReceivers;
  std::vector<CardReceiverIf::Ptr> cardReceivers;
  Mock<DeckIf> mockedDeck;
  DeckIf::Ptr deck;
  CardDealingDealer dealer;
};

TEST_CASE_METHOD(
    CardDealerTest,
    "On dealer deal cards, call callback when cards dealt", "dealing")
{
  bool called = false;
  dealer.DealCards([&called](){ called = true; });
  CHECK(called);
}

TEST_CASE_METHOD(
    CardDealerTest,
    "On dealer deal cards, give each cardReceiver and self two cards in correct order", 
    "dealing")
{
  dealer.DealCards([](){});
  Verify(Method(mockedCardReceivers[0], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[1], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[2], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[3], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[0], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[1], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[2], ReceiveCard),
         Method(mockedDeck, Draw),
         Method(mockedCardReceivers[3], ReceiveCard)).Exactly(Once);
}

TEST_CASE_METHOD(
    CardDealerTest,
    "Dealer as card provider, use cardProvider to distribute cards", 
    "dealing")
{
  auto card = Card{Suit::Hearts, Rank::Two};
  When(Method(mockedDeck, Draw)).Return(card);
  CHECK(card == dealer.GetCard());
  Verify(Method(mockedDeck, Draw)).Exactly(Once);
}

TEST_CASE_METHOD(
    CardDealerTest,
    "Dealer shuffles deck when no more cards left in deck", 
    "dealing")
{
  When(Method(mockedDeck, CardsLeft)).Return(0);
  (void)dealer.GetCard(); 
  Verify(Method(mockedDeck, Shuffle)).Exactly(Once);
}

