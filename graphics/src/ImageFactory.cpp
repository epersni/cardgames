#include "ImageFactory.hpp"

namespace cardgames::graphics
{

ImageFactory::ImageFactory(const std::string &pathPrefix)
  : mPathPrefix(pathPrefix)
{
}

Image ImageFactory::CreateImage(const std::string& filename) const
{
  return Image(mPathPrefix + "/" + filename);
}

}
