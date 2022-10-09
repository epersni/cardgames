#include "Player.hpp"
#include "Hand.hpp"

#include <algorithm>

namespace cardgames::graphics
{

Player::Player(const blackjack::game::PlayerIf::Ptr& player,
               const TextureFactoryIf::Ptr& textureFactory,
               const TextFactoryIf::Ptr& textFactory,
               const config::Player& config)
  : mPlayer(player)
  , mName(textFactory->CreateText(config.name, "Player X"))
  , mInstruction(textFactory->CreateText(config.instruction, "Place your bet"))
  , mCredits(textFactory->CreateText(config.credits, "$10000"))
{
  Transform(config.transform);

  config::Position nextHandOffset = { 0, 0 };
  for(const auto &hand : mPlayer->GetHands())
  {
    auto handNode = Hand(hand, textureFactory, textFactory, config.hand);
    handNode.move(nextHandOffset.x, nextHandOffset.y);
    nextHandOffset.x += config.handsOffset.x;
    nextHandOffset.y += config.handsOffset.y;
    AddChild(std::make_unique<Hand>(std::move(handNode)));
  }

  for(auto button : config.buttons)
  {
    auto buttonNode = Button(button, textureFactory, textFactory);
    AddChild(std::make_unique<Button>(std::move(buttonNode)));
  }

  mHeadUpDisplayBox.setSize(sf::Vector2f(config.headUpDisplayBox.size.x,
                                         config.headUpDisplayBox.size.y));
  mHeadUpDisplayBox.setFillColor(sf::Color(config.headUpDisplayBox.shape.fillcolor));
  mHeadUpDisplayBox.setOutlineColor(sf::Color(config.headUpDisplayBox.shape.outlinecolor));
  mHeadUpDisplayBox.setOutlineThickness(config.headUpDisplayBox.shape.outline);
  // TODO: Fixa en funktion i Node.hpp för att lägga till en transformable och då alignas den enligt:
  mHeadUpDisplayBox.setPosition(config.headUpDisplayBox.shape.transform.position.x,
                                config.headUpDisplayBox.shape.transform.position.y);
  mHeadUpDisplayBox.setScale(config.headUpDisplayBox.shape.transform.scale.x,
                             config.headUpDisplayBox.shape.transform.scale.y);
  mHeadUpDisplayBox.setRotation(config.headUpDisplayBox.shape.transform.angle);
  
  Align(mHeadUpDisplayBox);
  Align(mName);
  Align(mInstruction);
  Align(mCredits);
}

void Player::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(mHeadUpDisplayBox);
  target.draw(mName);
  target.draw(mCredits);
  target.draw(mInstruction);
}

}

