#include "TreeNode.hpp"

namespace cardgame::blackjack::view
{

void TreeNode::add_child(const TreeNode& node)
{
  m_children.push_back(node);
}

void TreeNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(const auto& drawable : m_children)
  {
    target.draw(drawable, states);
  }
}

}
