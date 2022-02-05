cmake_minimum_required(VERSION 3.19)

add_subdirectory(game)

add_executable(blackjack
               main.cpp)

target_link_libraries(
  blackjack 
  PRIVATE 
  logging 
  cardgamescommon
  sfml-graphics 
  sfml-window
  sfml-system)
