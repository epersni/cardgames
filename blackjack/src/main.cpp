#include "Betting.hpp"
#include "CardDealingDealer.hpp"
#include "CardShoe.hpp"
#include "DeckFactory.hpp"
#include "Game.hpp"
#include "GameStateDistributor.hpp"
#include "KeyEventPublisher.hpp"
#include "Logging.hpp"
#include "Player.hpp"
#include "PlayersQueue.hpp"
#include "PlayingDealerHand.hpp"
#include "TimeController.hpp"
#include "OutcomeDistributor.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace cardgames;
using namespace cardgames::blackjack;

int main()
{
  auto shallExit = false;

  common::KeyEventPublisher keyEventPublisher;

  keyEventPublisher.subscribeToKeyPressed(
      common::KeyEventPublisher::Key::Q,
      [&shallExit](){ std::cout << "Exiting now then..."; shallExit = true; });

  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);
  
  auto log = logging::Logger::createLogger("main");
  
  log.info("Starting Blackjack Application");

  auto cardShoe = std::make_shared<game::CardShoe>(
      std::make_shared<cards::DeckFactory>());
  
  auto gameStateDistributor = std::make_shared<game::GameStateDistributor>();

  auto playersQueue = std::make_shared<game::PlayersQueue>();

  auto timeController = std::make_shared<game::TimeController>();
  
  auto dealer = 
    std::make_shared<game::PlayingDealerHand>(cardShoe, timeController);
 
  auto cardDealer = 
    std::make_shared<game::CardDealingDealer>(cardShoe);

  auto player = std::make_shared<game::Player>(
      gameStateDistributor,
      playersQueue,
      std::make_shared<game::Betting>(),
      nullptr/* PlayingControlsIf */,
      cardDealer,
      cardShoe,
      timeController);

  auto outcomeDistributor = std::make_shared<game::OutcomeDistributor>();
    
  auto game =
    std::make_shared<game::Game>(
        playersQueue,
        dealer,
        timeController,
        nullptr,/* OutcomeProvider */
        outcomeDistributor,/* outcomeDistributor */
        gameStateDistributor,
        cardDealer);
  
  game->StartGame();

  const sf::Time timePerFrame = sf::seconds(1.f/60.f);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Clock clock;
  while (window.isOpen() && !shallExit)
  {
    /* HANDLING TIME */
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > timePerFrame)
    {
      timeSinceLastUpdate -= timePerFrame;
      timeController->
        IncrementGameTimeMs(timePerFrame.asMilliseconds());
      
      shallExit = game->IsGameOver();

      /* BEGIN PROCESS EVENTS */
      sf::Event event;
      if (window.pollEvent(event))
      {
        switch(event.type)
        {
          case sf::Event::EventType::KeyPressed:
            {
              keyEventPublisher.handleKeyPressed(event.key.code);
              break;
            }
          case sf::Event::EventType::KeyReleased:
            //TODO: add to keyEventPublisher
            break;
          case sf::Event::Closed:
            {
              window.close();
              break;
            }
          default:
            break;
        }
      }
      /* END PROCESS EVENTS */
    }
    /* RENDER HERE */
    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}

