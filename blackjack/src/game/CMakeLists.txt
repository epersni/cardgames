add_library(blackjackgame SHARED "")

target_include_directories(blackjackgame PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
  blackjackgame 
  logging
  cardgamescommon
)

target_sources(
  blackjackgame
  PRIVATE
    CardDealingDealer.cpp 
    CardShoe.cpp 
    Game.cpp 
    GameStateDistributor.cpp 
    OutcomeDistributor.cpp 
    OutcomeFactory.cpp 
    Player.cpp 
    PlayerController.cpp
    PlayersQueue.cpp 
    PlayingDealerHand.cpp 
    PlayingUserHand.cpp 
    TimeController.cpp
)


