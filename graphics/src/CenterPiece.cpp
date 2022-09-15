#include "CenterPiece.hpp"
#include "ShapeConfig.hpp"

namespace cardgames::graphics
{

CenterPiece::CenterPiece(const TextFactoryIf::Ptr& textFactory)
  : mTitle(textFactory->CreateText("centerpiece.title","BlackJack"))
  , mRow1(textFactory->CreateText("centerpiece.row1","Pays 3 to 2"))
  , mRow2(textFactory->CreateText("centerpiece.row2","Dealer must draw to 16 and stand on all 17s"))
  , mCircle(400, 900)
{
  //TODO: shapefactory?
  ShapeConfig shapeConfig{ 0x0, 0x575555ff, 2 };
  mCircle.setFillColor(sf::Color(shapeConfig.fillcolor));
  mCircle.setOutlineColor(sf::Color(shapeConfig.outlinecolor));
  mCircle.setOutlineThickness(shapeConfig.outline);

  CenterOrigin(mTitle);
  CenterOrigin(mCircle);
  CenterOrigin(mRow1);
  CenterOrigin(mRow2);
  
  mTitle.setPosition(0, -100);
  mRow1.setPosition(0, 0);
  mRow2.setPosition(0, 70);
}

void CenterPiece::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mCircle, states);
  target.draw(mTitle, states);
  target.draw(mRow1, states);
  target.draw(mRow2, states);
}

}
