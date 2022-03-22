add_library(blackjackgame SHARED "")

target_include_directories(blackjackgame PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(blackjackgame logging)

target_sources(
  blackjackgame
  PRIVATE
    Player.cpp 
    PlayersQueue.cpp 
    CardDealingDealer.cpp 
    Game.cpp 
    GameStateDistributor.cpp 
    OutcomeDistributor.cpp 
    OutcomeFactory.cpp 
    PlayingDealerHand.cpp 
    PlayingUserHand.cpp 
    TimeController.cpp
)


