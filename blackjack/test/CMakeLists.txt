include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.6
)
FetchContent_MakeAvailable(Catch2)

find_package(FakeIt REQUIRED)

#add_library(catch_main STATIC main.cpp)
#target_link_libraries(catch_main PUBLIC Catch2::Catch2)

add_executable(test_blackjack
               PlayingUserHandTest.cpp
               CardDealerTest.cpp
               GameStateDistributorTest.cpp
               GameTest.cpp
               OutcomeDistributorTest.cpp
               OutcomeFactoryTest.cpp
               #PlayersQueueControllerTest.cpp
               #               PlayingDealerHandTest.cpp
               TimeControllerTest.cpp
               )
target_link_libraries(test_blackjack 
                      PRIVATE 
                      blackjackgame
                      cards
                      Catch2::Catch2
                      catch_main 
                      FakeIt::FakeIt)

add_custom_target(check_blackjack
     COMMAND ${CMAKE_CTEST_COMMAND}
             --force-new-ctest-process
             --output-on-failure
     DEPENDS test_blackjack
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(test_blackjack)



