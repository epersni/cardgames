#ifndef CARDGAMES_GRAPHICS_CONFIG_BLACKJACK_CONFIG_HPP
#define CARDGAMES_GRAPHICS_CONFIG_BLACKJACK_CONFIG_HPP

#include "Blackjack.hpp"
#include "ConfigProviderIf.hpp"

#include <filesystem>
#include <memory>
#include <string>

namespace cardgames::graphics::config
{

class BlackjackConfig : public ConfigProviderIf<Blackjack>
{
public:
  BlackjackConfig(std::filesystem::path configFilePath);
  const Blackjack& GetConfig() const override;
private:
  Blackjack mBlackjack;
};

}

#endif



