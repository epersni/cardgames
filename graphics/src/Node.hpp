#ifndef CARDGAMES_GRAPHICS_NODE_HPP
#define CARDGAMES_GRAPHICS_NODE_HPP

#include "config/include/Transform.hpp"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
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
  void Align(sf::Transformable& object) const;
  void Transform(const config::Transform& transform);
  void Transform(const config::Transform& transform, sf::Transformable& object);
  //TODO: should be possible with templates
  void CenterOrigin(sf::Sprite& object);
  void CenterOrigin(sf::Text& object);
  void CenterOrigin(sf::Shape& object);
private:
  std::vector<Ptr> mChildren;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
};

}

#endif
