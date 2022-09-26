#include "ViewFactory.hpp"
#include "TextureFactory.hpp"
#include "TextFactory.hpp"
#include "BlackJackView.hpp"

#include "config/include/BlackjackConfig.hpp"

namespace cardgames::graphics
{
namespace
{
  struct DemoHand : public blackjack::game::PlayableHandIf
  {

    void Play(DonePlayingCb callback) override {}
    bool IsPlaying() const override { return false; }
    unsigned int GetTotal() const override { return 20; }
    std::vector<cards::Card> GetCards() const override
    {
      return { {cards::Suit::Hearts, cards::Rank::Ten},
               {cards::Suit::Clubs, cards::Rank::Seven},
               {cards::Suit::Spades, cards::Rank::Jack},
               {cards::Suit::Spades, cards::Rank::Six},
               {cards::Suit::Diamonds, cards::Rank::Ten}};
    }
    cards::BlackjackHandIf::Status GetStatus() const override
    {
      return cards::BlackjackHandIf::Status::Numeric;
    }
  };

  struct DemoPlayer : public blackjack::game::PlayerIf
  {
    std::vector<blackjack::game::PlayableHandIf::Ptr> GetHands() const override
    {
      return { std::make_shared<DemoHand>(), std::make_shared<DemoHand>() };
    }
  };
}

ViewIf::Ptr ViewFactory::CreateDemoBlackJackView(
      std::filesystem::path config) const
{
  config::BlackjackConfig blackjackConfig(config);
  std::vector<blackjack::game::PlayerIf::Ptr> players =
  {
    std::make_shared<DemoPlayer>(),
    std::make_shared<DemoPlayer>(),
    std::make_shared<DemoPlayer>(),
    std::make_shared<DemoPlayer>()
  };

  return std::make_shared<BlackJackView>(
      std::make_shared<DemoHand>(),
      players,
      std::move(blackjackConfig.GetConfig()),
      std::make_shared<TextureFactory>("/home/nicklas/src/cardgames/graphics/images/"),
      std::make_shared<TextFactory>("/home/nicklas/src/cardgames/graphics/fonts/"));
}

ViewIf::Ptr ViewFactory::CreateBlackJackView(
    cardgames::blackjack::game::PlayableHandIf::Ptr dealerHand,
    std::vector<cardgames::blackjack::game::PlayerIf::Ptr> players,
    std::filesystem::path config) const
{
  config::BlackjackConfig blackjackConfig(config);

  return std::make_shared<BlackJackView>(
      dealerHand,
      players,
      std::move(blackjackConfig.GetConfig()),
      std::make_shared<TextureFactory>("/home/nicklas/src/cardgames/graphics/images/"),
      std::make_shared<TextFactory>("/home/nicklas/src/cardgames/graphics/fonts/"));
}
}

