#ifndef CARDGAMES_GRAPHICS_VIEW_IF_HPP
#define CARDGAMES_GRAPHICS_VIEW_IF_HPP

#include <SFML/Window/Event.hpp> //TODO: can we have our own interface for events?

#include <cstdint>
#include <memory>
#include <string>

namespace cardgames::graphics
{

struct ViewIf
{
  using Ptr = std::shared_ptr<ViewIf>;
  virtual bool IsWindowOpen() const = 0;
  virtual bool PollEvent(sf::Event& event) = 0;
  virtual void CloseWindow() = 0;
  virtual void Update(uint32_t timeMs) = 0;
  virtual void Render() = 0;
};

}

#endif

