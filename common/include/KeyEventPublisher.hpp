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
      B = sf::Keyboard::Key::B,
      Q = sf::Keyboard::Key::Q,
      Z = sf::Keyboard::Key::Z,
      Num0 = sf::Keyboard::Key::Num0,
      Num1 = sf::Keyboard::Key::Num1,
      Num2 = sf::Keyboard::Key::Num2,
      Num3 = sf::Keyboard::Key::Num3,
      Num4 = sf::Keyboard::Key::Num4,
      Num5 = sf::Keyboard::Key::Num5,
      Num6 = sf::Keyboard::Key::Num6,
      Num7 = sf::Keyboard::Key::Num7,
      Num8 = sf::Keyboard::Key::Num8,
      Num9 = sf::Keyboard::Key::Num9,
    };

    void subscribeToKeyPressed(Key key, const Cb& callback); 
    void handleKeyPressed(sf::Keyboard::Key keyPressed) const;
  private:
    std::map<Key, std::vector<Cb>> mKeySubscriberMap;
};

std::ostream& operator<<(std::ostream& os, const KeyEventPublisher::Key& key);

}

#endif
