#ifndef CARDGAMES_GRAPHICS_IMAGEFACTORY_HPP
#define CARDGAMES_GRAPHICS_IMAGEFACTORY_HPP

#include "ImageFactoryIf.hpp"

namespace cardgames::graphics
{

class ImageFactory : public ImageFactoryIf
{
  public:
    ImageFactory(const std::string &pathPrefix);
    Image CreateImage(const std::string filename) const;
  private:
    const std::string mPathPrefix;
};

}

#endif

