#ifndef VIEW_TREENODE_HPP
#define VIEW_TREENODE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <vector>
#include <functional>

namespace cardgame::blackjack::view
{

class TreeNode : public sf::Drawable
{
  public:
    void add_child(const TreeNode& node);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    
  private:
    std::vector<std::reference_wrapper<const sf::Drawable>> m_children;
};

}

#endif
