#include "OutcomeDistributor.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

TEST_CASE("Creating a OutcomeDistributor", "OutcomeDistributor")
{
  (void)OutcomeDistributor();
}

TEST_CASE("Single Outcome subscriber", "OutcomeDistributor")
{
  auto outcome = GENERATE(Outcome::BlackJack, 
                        Outcome::Win,
                        Outcome::Draw, 
                        Outcome::Lose);
  
  Mock<OutcomeReceiverIf> receiver; 
  Mock<PlayableHandIf> player;
  Fake(Method(receiver, ReceiveOutcomes));
  OutcomeDistributor distributor;
  distributor.Subscribe(MockPtr(OutcomeReceiverIf, receiver));
  OutcomeReceiverIf::PlayerOutcomeMap outcomeMap;
  outcomeMap[MockPtr(PlayableHandIf, player)] = outcome;
  distributor.ReceiveOutcomes(std::move(outcomeMap));
  Verify(Method(receiver, ReceiveOutcomes)).Once();
}


