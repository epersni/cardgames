#include "Logging.hpp"
#include "KeyEventPublisher.hpp"
#include "GameStateDistributor.hpp"
#include "CardDealingDealer.hpp"


#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

#include <SFML/Graphics.hpp>

using namespace cardgames;

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

  auto gameStateDistributor = std::make_shared<blackjack::game::GameStateDistributor>();

  auto dealer = std::make_shared<blackjack::game::CardDealingDealer>();

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

