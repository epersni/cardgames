cmake_minimum_required(VERSION 3.19)

add_subdirectory(game)

add_executable(blackjack
               main.cpp)

set(CMAKE_BUILD_TYPE Debug)

target_link_libraries(
  blackjack 
  PRIVATE 
  blackjackgame
  cardgamescommon
  cards
  graphics
  logging 
  sfml-graphics 
  sfml-window
  sfml-system)
