#ifndef VIEW_ANIMATION_HPP
#define VIEW_ANIMATION_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/System/Clock.hpp>

#include <json/value.h>

#include <string>

namespace slotmachine {
namespace view {

class Animation : public sf::Drawable, public sf::Transformable
{
  public:
    Animation(const std::string& texturepackFile,
              const std::string& configFile);
    void setPosition(float x, float y);
  private:
    sf::Texture mTexture;
    mutable sf::Sprite mSprite;
    const std::string mConfigFile;
    Json::Value mFramesCfg;
    mutable unsigned int mCurrentFrame;
    mutable sf::Clock mClock;
    
    void setNextFrame() const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

}}

#endif

