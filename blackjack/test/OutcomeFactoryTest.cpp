#include "OutcomeFactory.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace cardgames::cards;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct OutcomeFactoryTest
{
  OutcomeFactoryTest()
  {
    Fake(Method(player, GetTotal));
    Fake(Method(dealer, GetTotal));
    Fake(Method(player, GetStatus));
    Fake(Method(dealer, GetStatus));
  }
  Mock<PlayableHandIf> player;
  Mock<PlayableHandIf> dealer;
};


TEST_CASE("Creating a OutcomeFactory", "OutcomeFactory")
{
  (void)OutcomeFactory();
}

TEST_CASE_METHOD(
    OutcomeFactoryTest, 
    "Always lose if busted", 
    "OutcomeFactory")
{
  auto sum = GENERATE(range(2,50));
  When(Method(player, GetStatus))
    .AlwaysReturn(BlackjackHandIf::Status::Busted);
  When(Method(dealer, GetTotal)).AlwaysReturn(sum);
  CHECK(Outcome::Lose == 
        OutcomeFactory().CreateOutcome(MockPtr(PlayableHandIf, player),
                                       MockPtr(PlayableHandIf, dealer)));
}

TEST_CASE_METHOD(
    OutcomeFactoryTest, 
    "Always draw if equal to dealer and not busted",
    "OutcomeFactory")
{
  auto sum = GENERATE(range(2,21));
  auto playerStatus = sum == 21 ? 
                      BlackjackHandIf::Status::BlackJack :
                      BlackjackHandIf::Status::Numeric;
  When(Method(player, GetStatus)).AlwaysReturn(playerStatus);
  When(Method(dealer, GetStatus)).AlwaysReturn(playerStatus);
  When(Method(player, GetTotal)).AlwaysReturn(sum);
  When(Method(dealer, GetTotal)).AlwaysReturn(sum);
  CHECK(Outcome::Draw == 
        OutcomeFactory().CreateOutcome(MockPtr(PlayableHandIf, player),
                                       MockPtr(PlayableHandIf, dealer)));
}

TEST_CASE_METHOD(
    OutcomeFactoryTest, 
    "Always blackjack if blackjack and if dealer has not 21",
    "OutcomeFactory")
{
  auto sum = 20;
    GENERATE(take(30, 
             filter([](unsigned int i){ return i != 21; }, range(2,40))));
  
  When(Method(player, GetTotal)).AlwaysReturn(21);
  When(Method(player, GetStatus))
    .AlwaysReturn(BlackjackHandIf::Status::BlackJack);

  When(Method(dealer, GetTotal)).AlwaysReturn(sum);
  auto dealerStatus = sum > 21 ? 
                      BlackjackHandIf::Status::Busted :
                      BlackjackHandIf::Status::Numeric;
  When(Method(dealer, GetStatus)).AlwaysReturn(dealerStatus);

  CHECK(Outcome::BlackJack == 
        OutcomeFactory().CreateOutcome(MockPtr(PlayableHandIf, player),
                                       MockPtr(PlayableHandIf, dealer)));
}

TEST_CASE_METHOD(
    OutcomeFactoryTest, 
    "Always win if greater to dealer and less or equal than 21")
{
  auto playerSum = GENERATE(range(2,20));
  auto dealerSum = playerSum-1;

  When(Method(player, GetTotal)).AlwaysReturn(playerSum);
  When(Method(player, GetStatus))
    .AlwaysReturn(BlackjackHandIf::Status::Numeric);

  When(Method(dealer, GetTotal)).AlwaysReturn(dealerSum);
  When(Method(dealer, GetStatus))
    .AlwaysReturn(BlackjackHandIf::Status::Numeric); 

  CHECK(Outcome::Win == 
        OutcomeFactory().CreateOutcome(MockPtr(PlayableHandIf, player),
                                       MockPtr(PlayableHandIf, dealer)));
}

TEST_CASE_METHOD(
    OutcomeFactoryTest, 
    "Always win if not busted and dealer is busted")
{
  auto playerSum = GENERATE(range(2,20));
  auto dealerSum = GENERATE(range(22,30));
  When(Method(player, GetTotal)).AlwaysReturn(playerSum);
  When(Method(dealer, GetTotal)).AlwaysReturn(dealerSum);
  When(Method(player, GetStatus))
    .AlwaysReturn(BlackjackHandIf::Status::Numeric);
  When(Method(dealer, GetStatus))
    .AlwaysReturn(BlackjackHandIf::Status::Busted); 
  CHECK(Outcome::Win == 
        OutcomeFactory().CreateOutcome(MockPtr(PlayableHandIf, player),
                                       MockPtr(PlayableHandIf, dealer)));
}
