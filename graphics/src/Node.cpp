#include "Node.hpp" 

namespace cardgames::graphics
{

void Node::AddChild(Ptr child)
{
  mChildren.push_back(std::move(child));
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // Apply transform of current node
  states.transform *= getTransform();

  // Draw node and children with changed transform
  onDraw(target, states);
  for (std::size_t i = 0; i < mChildren.size(); ++i) //TODO: nicer foor loop
  {
    mChildren[i]->draw(target, states);
  }
}

void Node::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
  //Do nothing by default
}

}
