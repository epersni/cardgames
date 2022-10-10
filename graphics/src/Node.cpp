#include "Node.hpp" 

#include <cmath>

namespace cardgames::graphics
{

void Node::AddChild(Ptr child)
{
  mChildren.push_back(std::move(child));
}

void Node::Align(sf::Transformable& object) const
{
  object.setPosition(getPosition() + object.getPosition());
  object.setScale(getScale().x * object.getScale().x,
                  getScale().y * object.getScale().y);
  object.setRotation(getRotation() + object.getRotation());
}

void Node::Transform(const config::Transform& transform,
                     sf::Transformable& object)
{
  object.setRotation(transform.angle);
  object.setPosition(transform.position.x, transform.position.y);
  object.setScale(transform.scale.x, transform.scale.x);
}

void Node::Transform(const config::Transform& transform)
{
  setRotation(transform.angle);
  setPosition(transform.position.x, transform.position.y);
  setScale(transform.scale.x, transform.scale.x);
}

void Node::CenterOrigin(sf::Sprite& object)
{
  sf::FloatRect bounds = object.getLocalBounds();
  object.setOrigin(std::floor(bounds.left + bounds.width / 2.f),
                    std::floor(bounds.top + bounds.height / 2.f));
}

void Node::CenterOrigin(sf::Text& object)
{
  sf::FloatRect bounds = object.getLocalBounds();
  object.setOrigin(std::floor(bounds.left + bounds.width / 2.f),
                    std::floor(bounds.top + bounds.height / 2.f));
}

void Node::CenterOrigin(sf::Shape& object)
{
  sf::FloatRect bounds = object.getLocalBounds();
  object.setOrigin(std::floor(bounds.left + bounds.width / 2.f),
                    std::floor(bounds.top + bounds.height / 2.f));
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // Apply transform of current node
  states.transform *= getTransform();

  // Draw node and children with changed transform
  for (std::size_t i = 0; i < mChildren.size(); ++i) //TODO: nicer foor loop
  {
    mChildren[i]->draw(target, states);
  }
  onDraw(target, states);
}

void Node::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  //Do nothing by default
}

}
