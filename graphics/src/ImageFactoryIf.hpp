#ifndef CARDGAMES_GRAPHICS_IMAGEFACTORY_IF_HPP
#define CARDGAMES_GRAPHICS_IMAGEFACTORY_IF_HPP

#include "Image.hpp"

#include <memory>
#include <string>

namespace cardgames::cards
{

struct ImageFactoryIf
{
  using Ptr = std::shared_ptr<DeckFacotyIf>;
  virtual Image CreateImage(const std::string& imagePath) const = 0;
};

}

#endif
