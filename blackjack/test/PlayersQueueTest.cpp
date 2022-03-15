#include "PlayersQueue.hpp"

#include <fakeit.hpp>
#include <catch2/catch.hpp>

#define MockPtr(t,p) (std::shared_ptr<t>(&p.get(),[](...){}))

using namespace cardgames::cards;
using namespace cardgames::blackjack::game;
using namespace fakeit;

struct PlayersQueueTest
{ 
  PlayersQueueTest()
  {
    Fake(Method(hand1, Play));
    Fake(Method(hand2, Play));
    Fake(Method(hand3, Play));
    Fake(Method(hand4, Play));
    
    Fake(Method(hand1b, Play));
    Fake(Method(hand2b, Play));
    Fake(Method(hand3b, Play));
    Fake(Method(hand4b, Play));
  }
  Mock<PlayableHandIf> hand1;
  Mock<PlayableHandIf> hand2;
  Mock<PlayableHandIf> hand3;
  Mock<PlayableHandIf> hand4;
  
  Mock<PlayableHandIf> hand1b;
  Mock<PlayableHandIf> hand2b;
  Mock<PlayableHandIf> hand3b;
  Mock<PlayableHandIf> hand4b;
  
  PlayersQueue queue;
};

TEST_CASE_METHOD(
    PlayersQueueTest,
    "Initially, the queue is empty"
    "[playersqueue]")
{
  CHECK(!queue.AnyInQueue());
}

TEST_CASE_METHOD(
    PlayersQueueTest,
    "Adding 4 hands, then pop in FIFO order",
    "[playersqueue]")
{
  queue.Inject(MockPtr(PlayableHandIf,hand1));
  queue.Inject(MockPtr(PlayableHandIf,hand2));
  queue.Inject(MockPtr(PlayableHandIf,hand3));
  queue.Inject(MockPtr(PlayableHandIf,hand4));
  CHECK(queue.AnyInQueue());
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  CHECK(!queue.AnyInQueue());
  Verify(Method(hand1,Play) + 
         Method(hand2,Play) +
         Method(hand3,Play) +
         Method(hand4,Play)).Exactly(Once);
}

TEST_CASE_METHOD(
    PlayersQueueTest,
    "Adding 4 hands, Inject 1 hand after all, Pop FIFO order",
    "[playersqueue]")
{
  auto h1Ptr = MockPtr(PlayableHandIf,hand1);
  auto h2Ptr = MockPtr(PlayableHandIf,hand2);
  auto h3Ptr = MockPtr(PlayableHandIf,hand3);
  auto h4Ptr = MockPtr(PlayableHandIf,hand4);
  
  queue.Inject(h1Ptr);
  queue.Inject(h2Ptr);
  queue.Inject(h3Ptr);
  queue.Inject(h4Ptr);
  
  queue.InjectAfter(MockPtr(PlayableHandIf,hand1b), h1Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf,hand2b), h2Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf,hand3b), h3Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf,hand4b), h4Ptr);

  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});

  CHECK(!queue.AnyInQueue());

  Verify(Method(hand1,Play) + 
         Method(hand1b,Play) +
         Method(hand2,Play) +
         Method(hand2b,Play) +
         Method(hand3,Play) +
         Method(hand3b,Play) +
         Method(hand4,Play) +
         Method(hand4b,Play)).Exactly(Once);
}

TEST_CASE_METHOD(
    PlayersQueueTest,
    "Add 1 hand, inject 4 after",
    "[playersqueue]")
{
  auto h1Ptr = MockPtr(PlayableHandIf, hand1);
  queue.Inject(h1Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf, hand1b), h1Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf, hand2b), h1Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf, hand3b), h1Ptr);
  queue.InjectAfter(MockPtr(PlayableHandIf, hand4b), h1Ptr);

  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});
  queue.PopNextInQueue()->Play([](){});

  CHECK(!queue.AnyInQueue());

  Verify(Method(hand1,Play) + 
         Method(hand4b,Play) +
         Method(hand3b,Play) +
         Method(hand2b,Play) +
         Method(hand1b,Play)).Exactly(Once);
}
