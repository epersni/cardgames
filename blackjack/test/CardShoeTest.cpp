#include "CardShoe.hpp"
#include "DeckFactoryIf.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

using namespace cardgames::cards;
using namespace cardgames::blackjack::game;
using namespace fakeit;

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

struct CardShoeTest
{
  CardShoeTest()
    : deckFactory(MockPtr(DeckFactoryIf, mockedDeckFactory))
  {
    deck.PushTop(Card{Suit::Hearts, Rank::Two});
    When(Method(mockedDeckFactory, CreateBlackJackDeck)).AlwaysReturn(deck);
  }
  Mock<DeckFactoryIf> mockedDeckFactory;
  DeckFactoryIf::Ptr deckFactory;
  Deck deck;
};

TEST_CASE_METHOD(
    CardShoeTest,
    "CardShow creates a blackjack deck initially")
{
  CardShoe cardShoe(deckFactory);
  Verify(Method(mockedDeckFactory, CreateBlackJackDeck)).Exactly(Once);
}

TEST_CASE_METHOD(
    CardShoeTest,
    "CardShow creates a blackjack deck when no more cards left")
{
  CardShoe cardShoe(deckFactory);
  (void)cardShoe.GetCard();
  (void)cardShoe.GetCard();
  Verify(Method(mockedDeckFactory, CreateBlackJackDeck)).Exactly(2_Times);
}

