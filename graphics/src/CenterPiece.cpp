#include "CenterPiece.hpp"

namespace cardgames::graphics
{

CenterPiece::CenterPiece(const config::Centerpiece& config,
                         const TextFactoryIf::Ptr& textFactory)
  : mTitle(textFactory->CreateText(config.title, "BlackJack"))
  , mRow1(textFactory->CreateText(config.row1, "Pays 3 to 2"))
  , mRow2(textFactory->CreateText(config.row2, "Dealer must draw to 16 and stand on all 17s"))
  , mCircle(config.circle.radius, config.circle.points)
{
  Transform(config.transform);

  //TODO: yep, shape factory is needed
  mCircle.setFillColor(sf::Color(config.circle.shape.fillcolor));
  mCircle.setOutlineColor(sf::Color(config.circle.shape.outlinecolor));
  mCircle.setOutlineThickness(config.circle.shape.outline);
  mCircle.setPosition(config.circle.shape.transform.position.x,
                      config.circle.shape.transform.position.y);
  mCircle.setScale(config.circle.shape.transform.scale.x,
                   config.circle.shape.transform.scale.y);
  mCircle.setRotation(config.circle.shape.transform.angle);
  
  CenterOrigin(mTitle);
  CenterOrigin(mCircle);
  CenterOrigin(mRow1);
  CenterOrigin(mRow2);
}

void CenterPiece::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mCircle, states);
  target.draw(mTitle, states);
  target.draw(mRow1, states);
  target.draw(mRow2, states);
}

}
