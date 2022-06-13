#include "ViewFactory.hpp"
#include "BlackJackView.hpp"

namespace cardgames::graphics
{

ViewIf::Ptr ViewFactory::CreateBlackJackView(int width, int height) const
{
  return std::make_shared<BlackJackView>(width, height);
}
}

