#ifndef CARDGAMES_GRAPHICS_CONFIG_INCLUDE_CONFIG_PROVIDER_IF_HPP
#define CARDGAMES_GRAPHICS_CONFIG_INCLUDE_CONFIG_PROVIDER_IF_HPP

#include <memory>
#include <string>

namespace cardgames::graphics::config
{

template<typename T>
struct ConfigProviderIf
{
  using Ptr = std::shared_ptr<ConfigProviderIf<T>>;
  virtual const T& GetConfig() const = 0;
};

}

#endif


