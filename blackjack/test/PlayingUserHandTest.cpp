#include "PlayingUserHand.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>
#include <algorithm>

using namespace cardgames::blackjack::game;
using namespace cardgames::cards;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct PlayingUserTest
{
  PlayingUserTest()
    : cardProvider(MockPtr(CardProviderIf, mockedCardProvider))
    , timerProvider{MockPtr(TimerProviderIf, mockedTimerProvider)}
    , controlEnabler{MockPtr(HandControlEnablerIf, mockedControlEnabler)}
    , user(cardProvider, timerProvider, controlEnabler)
  {
    Fake(Method(mockedControlEnabler, EnableActions));
    Fake(Method(mockedTimerProvider, PlayingUserHandTimerCb));

    When(Method(mockedCardProvider, GetCard))
      .Return({Suit::Hearts, Rank::Four});
    
    When(Method(mockedControlEnabler, EnableActions))
      .AlwaysDo([this](auto actions)
        {
          mAllowedActions.clear();
          std::for_each(actions.begin(), actions.end(),
              [this](auto a)
              {
                mAllowedActions.insert(a);
              }
          );
        });
  }
  
  Mock<CardProviderIf> mockedCardProvider;
  CardProviderIf::Ptr cardProvider;

  Mock<TimerProviderIf> mockedTimerProvider;
  std::shared_ptr<TimerProviderIf> timerProvider;

  Mock<HandControlEnablerIf> mockedControlEnabler;
  HandControlEnablerIf::Ptr controlEnabler;

  PlayingUserHand user;
  
  HandControlEnablerIf::AllowedActions mAllowedActions;
};

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Initially, hand has no cards", "PlayingUserHand")
{
  CHECK(user.GetCards().size() == 0);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Initially, hand has 0 in total", "PlayingUserHand")
{
  CHECK(user.GetTotal() == 0);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Initially, hand is not playing", "PlayingUserHand")
{
  CHECK(user.IsPlaying() == false);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Get cards from playing hand",
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Two},
    { Suit::Hearts, Rank::Three},
    { Suit::Hearts, Rank::Four},
    { Suit::Hearts, Rank::Five},
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  auto cards = user.GetCards();
  CHECK(equal(cards_dealt.begin(), cards_dealt.end(), 
              cards.begin(), cards.end()));
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "On split, one card is removed and total is half", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Ten}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  CHECK(user.GetTotal() == 20);
  CHECK(user.Split() == cards_dealt[0]);
  CHECK(user.GetTotal() == 10);
}

/* This is for FakeIt */
bool operator==(std::set<HandAction> a1, std::set<HandAction> a2)
{
  return equal(a1.begin(), a1.end(), a2.begin(), a2.end());
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "After splitable hand dealt, on start playing, all actions are allowed", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Ten}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  user.Play([](){});
  auto expectedActions = 
  { 
    HandAction::Split, HandAction::Stand, HandAction::Double, HandAction::Hit 
  };
  CHECK(mAllowedActions == expectedActions);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "After non-splitable hand dealt, on start playing, all actions except split are allowed", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Eight}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  CHECK(user.GetCards().size() == 2);
  user.Play([](){});
  auto expectedActions = 
  { 
    HandAction::Stand, HandAction::Double, HandAction::Hit 
  };
  CHECK(mAllowedActions == expectedActions);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "After player have hit, split and double are no longer allowed", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Two},
    { Suit::Spades, Rank::Eight}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  user.Play([](){});
  mAllowedActions.clear();
  user.Hit();
  CHECK(mAllowedActions.count(HandAction::Split) == 0);
  CHECK(mAllowedActions.count(HandAction::Double) == 0);
  CHECK(mAllowedActions.count(HandAction::Stand) == 1);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "When player is bust, player is automatically done playing", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Ten}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  
  CHECK(user.GetTotal() == 20);
  bool doneCallbackCalled = false;
  user.Play([&doneCallbackCalled](){ doneCallbackCalled = true; });
  CHECK(user.IsPlaying());
  user.Hit();
  CHECK(user.GetTotal() == 24);
  CHECK(user.GetStatus() == BlackjackHandIf::Status::Busted);
  CHECK(!user.IsPlaying());
  CHECK(doneCallbackCalled);
  CHECK(mAllowedActions.empty());
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "On double, one card is added from cardprovider to the hand and then done playing", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Five}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  
  CHECK(user.GetTotal() == 15);
  bool doneCallbackCalled = false;
  user.Play([&doneCallbackCalled](){ doneCallbackCalled = true; });
  CHECK(user.IsPlaying());
  user.Double();
  Verify(Method(mockedCardProvider, GetCard)).Once();
  CHECK(!user.IsPlaying());
  CHECK(doneCallbackCalled);
  CHECK(mAllowedActions.empty());
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "On hit, one card is added from cardprovider to the hand", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Two}
  };
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});
  user.Play([](){});
  user.Hit();
  Verify(Method(mockedCardProvider, GetCard)).Once();
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "On stand, no more action available and not playing anymore", 
    "PlayingUserHand")
{
  std::vector<Card> cards_dealt = 
  {
    { Suit::Hearts, Rank::Ten},
    { Suit::Spades, Rank::Ten}
  };
  
  std::for_each(cards_dealt.begin(),
                cards_dealt.end(),
                [this](auto &c){user.ReceiveCard(c);});

  CHECK(!user.IsPlaying());
  bool doneCallbackCalled = false;
  user.Play([&doneCallbackCalled](){ doneCallbackCalled = true; });
  CHECK(user.IsPlaying());

  user.Stand();
  CHECK(mAllowedActions.empty());
  CHECK(!user.IsPlaying());
  CHECK(doneCallbackCalled);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "On player play, start playing timer", 
    "PlayingUserHand")
{
  user.Play([](){});
  Verify(Method(mockedTimerProvider, PlayingUserHandTimerCb)).Once();
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "On player timeout, no more action available and not playing anymore", 
    "PlayingUserHand")
{
  When(Method(mockedTimerProvider, PlayingUserHandTimerCb))
    .Do([](TimerProviderIf::TimeExpiredCb cb){ cb(); });
  bool doneCallbackCalled = false;
  user.Play([&doneCallbackCalled](){ doneCallbackCalled = true; });
  CHECK(doneCallbackCalled);
  CHECK(mAllowedActions.empty());
  CHECK(!user.IsPlaying());
}


