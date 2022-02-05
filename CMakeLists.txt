cmake_minimum_required(VERSION 3.19)

project(CardGames LANGUAGES CXX VERSION 0.1)

add_compile_options(-Wall -Wextra -pedantic)

#TODO: run 20! (or even better with 23!)
#set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(blackjack)
add_subdirectory(cards)
add_subdirectory(cmake)
add_subdirectory(common)
add_subdirectory(graphics)
add_subdirectory(logging)
