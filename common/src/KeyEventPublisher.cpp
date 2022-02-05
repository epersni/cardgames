#include "KeyEventPublisher.hpp"
#include "Logging.hpp"
#include <algorithm>

namespace cardgames::common{
namespace
{
  auto log = logging::Logger::createLogger("KeyEventPublisher");
}

void KeyEventPublisher::handleKeyPressed(sf::Keyboard::Key keyPressed) const
{
  const auto key = static_cast<Key>(keyPressed);
  
  log.trace("Handling pressed key = {}", key);

  if(mKeySubscriberMap.contains(key))
  {
    auto callbacks = mKeySubscriberMap.at(key);
    std::for_each(callbacks.begin(), callbacks.end(), [](Cb &c){ c(); }); 
  }
}

void KeyEventPublisher::subscribeToKeyPressed(Key key, const Cb& callback)
{
  log.debug("Subscribing to key = {}", key);
  mKeySubscriberMap[key].push_back(callback);
}

std::ostream& operator<<(std::ostream& os, const KeyEventPublisher::Key& key)
{
  switch(key)
  {
    case KeyEventPublisher::Key::A:
      os << "A"; break;
    case KeyEventPublisher::Key::Q:
      os << "Q"; break;
    default:
      os << "<unknown>"; break;
  }
  return os;
}


}
