#include "CardDealingDealer.hpp"
#include "CardShoe.hpp"
#include "DeckFactory.hpp"
#include "Game.hpp"
#include "GameStateDistributor.hpp"
#include "KeyEventPublisher.hpp"
#include "Logging.hpp"
#include "OutcomeDistributor.hpp"
#include "OutcomeFactory.hpp"
#include "Player.hpp"
#include "PlayerController.hpp"
#include "PlayersQueue.hpp"
#include "PlayingDealerHand.hpp"
#include "TimeController.hpp"
#include "ViewFactory.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace cardgames;
using namespace cardgames::blackjack;

int main()
{ 
  auto keyEventPublisher = std::make_shared<common::KeyEventPublisher>(); 
  
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

  auto player1Controls = 
    std::make_shared<game::PlayerController>(keyEventPublisher,
                                             common::KeyEventPublisher::Key::Num1,
                                             common::KeyEventPublisher::Key::Num2,
                                             common::KeyEventPublisher::Key::Num3,
                                             common::KeyEventPublisher::Key::Num4);

  auto player = std::make_shared<game::Player>(
      gameStateDistributor,
      playersQueue,
      player1Controls,
      player1Controls,
      cardDealer,
      cardShoe,
      timeController);

  auto outcomeDistributor = std::make_shared<game::OutcomeDistributor>();
    
  auto game =
    std::make_shared<game::Game>(
        playersQueue,
        dealer,
        timeController,
        std::make_shared<game::OutcomeFactory>(),
        outcomeDistributor,
        gameStateDistributor,
        cardDealer);
  
  graphics::ViewFactory viewFactory;
  auto view 
    //= viewFactory.CreateBlackJackView(dealer, {player}, "graphics-config-file.yml");
    = viewFactory.CreateDemoBlackJackView("graphics-config-file.yml");
  
  keyEventPublisher->subscribeToKeyPressed(
      common::KeyEventPublisher::Key::Q,
      [&](){ view->CloseWindow(); return 0; });
  
  //game->StartGame();

  const sf::Time timePerFrame = sf::seconds(1.f/60.f);
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  sf::Clock clock;
  while (view->IsWindowOpen() && !game->IsGameOver())
  {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > timePerFrame)
    {
      timeSinceLastUpdate -= timePerFrame;
      
      timeController->IncrementGameTimeMs(timePerFrame.asMilliseconds());
      
      sf::Event event;
      if (view->PollEvent(event))
      {
        switch(event.type)
        {
          case sf::Event::EventType::KeyPressed:
            {
              keyEventPublisher->handleKeyPressed(event.key.code);
              break;
            }
          case sf::Event::Closed:
            {
              view->CloseWindow();
              break;
            }
          default:
            break;
        }
      }
    }
    view->Update(timePerFrame.asMilliseconds());
    view->Render();
  }

  return 0;
}

