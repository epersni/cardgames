#include "ImageFactory.hpp"

namespace cardgames::graphics
{

ImageFactory::ImageFactory(const std::string &pathPrefix)
  : mPathPrefix(pathPrefix)
{
}

Image CreateImage(const std::string& filename)
{
  return Image(mPathPrefix + filename);
}
