#ifndef CARDGAMES_GRAPHICS_DECKIMAGEFACTORY_HPP
#define CARDGAMES_GRAPHICS_DECKIMAGEFACTORY_HPP

#include "ImageFactoryIf.hpp"

namespace cardgames::graphics
{

class DeckImageFactory : public ImageFactoryIf
{
  public:
    DeckImageFactory(const std::string& pathPrefix);
    Image CreateImage(const std::string& filename) const;
  private:
    const std::string mPathPrefix;
};

}

#endif


