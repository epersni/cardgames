#ifndef CARDGAME_COMMON_KEY_EVENT_MANAGER_HPP
#define CARDGAME_COMMON_KEY_EVENT_MANAGER_HPP

#include <SFML/Window/Keyboard.hpp>

#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>

namespace cardgames::common{

class KeyEventPublisher
{
  public:
    using Ptr = std::shared_ptr<KeyEventPublisher>;
    using Cb = std::function<void()>;

    enum class Key
    {
      A = sf::Keyboard::Key::A,
      Q = sf::Keyboard::Key::Q
    };

    void subscribeToKeyPressed(Key key, const Cb& callback); 
    void handleKeyPressed(sf::Keyboard::Key keyPressed) const;
  private:
    std::map<Key, std::vector<Cb>> mKeySubscriberMap;
};

std::ostream& operator<<(std::ostream& os, const KeyEventPublisher::Key& key);

}

#endif
