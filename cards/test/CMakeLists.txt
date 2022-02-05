include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.6
)
FetchContent_MakeAvailable(Catch2)

add_library(catch_main STATIC main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)

add_executable(tests 
               CardTest.cpp
               DeckTest.cpp
               DeckFactoryTest.cpp
               BlackjackHandTest.cpp
               )
target_link_libraries(tests PRIVATE catch_main cards)

add_custom_target(check 
     COMMAND ${CMAKE_CTEST_COMMAND}
             --force-new-ctest-process
             --output-on-failure
     DEPENDS tests
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(tests)


