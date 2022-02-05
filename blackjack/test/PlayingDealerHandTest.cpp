#include "PlayingDealerHand.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::cards;
using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct PlayingDealerTest
{
  PlayingDealerTest()
    : cardProvider(MockPtr(CardProviderIf, mockedCardProvider))
    , timerProvider{MockPtr(TimerProviderIf, mockedTimerProvider)}
    , dealer(cardProvider, timerProvider)
  {
    Fake(Method(mockedCardProvider, GetCard));
    When(Method(mockedTimerProvider, DealerDecisionTimerCb)).AlwaysDo(
        [](TimerProviderIf::TimeExpiredCb cb){ cb(); });
  }
  Mock<TimerProviderIf> mockedTimerProvider;
  std::shared_ptr<TimerProviderIf> timerProvider;
  Mock<CardProviderIf> mockedCardProvider;
  CardProviderIf::Ptr cardProvider;
  PlayingDealerHand dealer;
};

TEST_CASE_METHOD(
    PlayingDealerTest,
    "On dealer play, dealer draws cards until 17 or higher", "dealerplaying")
{
  SECTION("2->5->7->11->17")
  {
    When(Method(mockedCardProvider, GetCard))
      .Return({Suit::Hearts, Rank::Two})
      .Return({Suit::Hearts, Rank::Three})
      .Return({Suit::Spades, Rank::Two})
      .Return({Suit::Hearts, Rank::Four})
      .Return({Suit::Spades, Rank::Six});
    dealer.Play([](){});
    Verify(Method(mockedCardProvider, GetCard)).Exactly(5_Times);
  }
  SECTION("10->16->18")
  {
    When(Method(mockedCardProvider, GetCard))
      .Return({Suit::Hearts, Rank::Ten})
      .Return({Suit::Hearts, Rank::Six})
      .Return({Suit::Hearts, Rank::Two});
    dealer.Play([](){});
    Verify(Method(mockedCardProvider, GetCard)).Exactly(3_Times);
  }
}

TEST_CASE_METHOD(
    PlayingDealerTest,
    "Dealer uses timer for each decisions", "dealerplaying")
{
  SECTION("Two cards")
  {
    When(Method(mockedCardProvider, GetCard))
      .Return({Suit::Hearts, Rank::Ten})
      .Return({Suit::Hearts, Rank::Seven});
    dealer.Play([](){});
    Verify(Method(mockedTimerProvider, DealerDecisionTimerCb)).Exactly(2_Times);
  }
  SECTION("Five cards")
  {
    When(Method(mockedCardProvider, GetCard))
      .Return({Suit::Hearts, Rank::Two})
      .Return({Suit::Hearts, Rank::Three})
      .Return({Suit::Spades, Rank::Two})
      .Return({Suit::Hearts, Rank::Four})
      .Return({Suit::Spades, Rank::Six});
    dealer.Play([](){});
    Verify(Method(mockedTimerProvider, DealerDecisionTimerCb)).Exactly(5_Times);
  }
}

