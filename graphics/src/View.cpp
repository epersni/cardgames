#include "View.hpp"

#include <iostream>

namespace cardgames::graphics
{

View::View()//KeyEventPublisher::Ptr keyEventPublisher)
  //: mKeyEventPublisher(keyEventPublisher)
  : mBackground("images/background.jpg")
  , mDealerHand()
{
//  mKeyEventPublisher->
//    subscribeToKeyPressed(KeyEventPublisher::Key::A,
//                          [this](){ onKeyPressed(); });
//  mDealerHand.setPosition(200, 280);
}

void View::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mBackground, states);
  target.draw(mDealerHand, states);
}

void View::onKeyPressed()
{
  mDealerHand.addCard();
  std::cout << "A pressed on and view registered " << std::endl;
}

}
