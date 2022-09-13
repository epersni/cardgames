#include "CenterPiece.hpp"

namespace cardgames::graphics
{

CenterPiece::CenterPiece(const TextFactoryIf::Ptr& textFactory)
  : mTitle(textFactory->CreateText("centerpiece.title","BlackJack"))
  , mRow1(textFactory->CreateText("centerpiece.row1","Pays 3 to 2"))
  , mRow2(textFactory->CreateText("centerpiece.row2","Dealer must draw to 16 and stand on all 17s"))
{
  mTitle.setPosition(0, -100);
  mRow1.setPosition(0, 0);
  mRow2.setPosition(0, 70);

  //TODO align center
  sf::FloatRect textRect1 = mRow1.getLocalBounds();
  mRow1.setOrigin(textRect1.left + textRect1.width/2.0f,
                     textRect1.top  + textRect1.height/2.0f);
  //TODO align center
  sf::FloatRect textRect2 = mRow2.getLocalBounds();
  mRow2.setOrigin(textRect2.left + textRect2.width/2.0f,
                     textRect2.top  + textRect2.height/2.0f);
  //TODO align center
  sf::FloatRect textRect3 = mTitle.getLocalBounds();
  mTitle.setOrigin(textRect3.left + textRect3.width/2.0f,
                     textRect3.top  + textRect3.height/2.0f);
}

void CenterPiece::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mTitle, states);
  target.draw(mRow1, states);
  target.draw(mRow2, states);
}

}
