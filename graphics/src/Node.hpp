#ifndef CARDGAMES_GRAPHICS_NODE_HPP
#define CARDGAMES_GRAPHICS_NODE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>
#include <vector>

namespace cardgames::graphics
{

class Node 
  : public sf::Drawable
  , public sf::Transformable
{
public:
  using Ptr = std::unique_ptr<Node>;
  void AddChild(Ptr child);
private:
  sf::Transform m_transform;
  std::vector<Ptr> mChildren;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif
