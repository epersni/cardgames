#ifndef CARDGAMES_BLACKJACK_GAME_KEYBOARD_CONTROLLER_HPP
#define CARDGAMES_BLACKJACK_GAME_KEYBOARD_CONTROLLER_HPP

#include "UserControlsIf.hpp"
#include "UserAction.hpp"

namespace cardgames::blackjack::game{

class KeyboardController : public UserControlsIf
{
public:
  using KeyActionMap = std::map<Key, UserAction>;
  using ActionFunctionMap = std::map<UserAction, std::function<void()>;

  UserController(const KeyActionMap& keyActionMap,
                 const ActionFunctionMap& actionFunctionMap);
  
  EnableControls(std::vector<UserAction> allowedActions);

  bool IsEnabled() const; //TODO: this is for GUI to know if it shall show something

private:
};

}

#endif


