#ifndef CARDGAMES_GRAPHICS_VIEW_FACTORY_HPP
#define CARDGAMES_GRAPHICS_VIEW_FACTORY_HPP

#include "ViewIf.hpp"

namespace cardgames::graphics
{

class ViewFactory
{
public:
  ViewIf::Ptr CreateBlackJackView(int width, int height) const;
};

}

#endif


