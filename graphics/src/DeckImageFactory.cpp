#include "DeckImageFactory.hpp"

namespace cardgames::graphics
{

DeckImageFactory::DeckImageFactory(const std::string& pathPrefix)
  : mPathPrefix(pathPrefix)
{
}

DeckImageFactory CreateImage(const std::string& filename)
{
  return Image(mPathPrefix + filename);
}

}
