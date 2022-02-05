#include "PlayingUserHand.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace cardgames::cards;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct PlayingUserTest
{
  PlayingUserTest()
    : cardProvider(MockPtr(CardProviderIf, mockedCardProvider))
    , timerProvider{MockPtr(TimerProviderIf, mockedTimerProvider)}
    , user(cardProvider, timerProvider)
  {
  }
  Mock<TimerProviderIf> mockedTimerProvider;
  std::shared_ptr<TimerProviderIf> timerProvider;
  Mock<CardProviderIf> mockedCardProvider;
  CardProviderIf::Ptr cardProvider;
  PlayingUserHand user;
};

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Initially, players has no cards", "PlayingUserHand")
{
  CHECK(user.GetCards().size() == 0);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Initially, players has 0 in total", "PlayingUserHand")
{
  CHECK(user.GetTotal() == 0);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "Initially, players has hand status 'Numeric'", "PlayingUserHand")
{
  CHECK(user.GetStatus() == BlackjackHandIf::Status::Numeric);
}

TEST_CASE_METHOD(
    PlayingUserTest, 
    "When players turn, enable the controls for this playing user",
    "PlayingUserHand")
{
  CHECK(user.GetStatus() == BlackjackHandIf::Status::Numeric);
}
