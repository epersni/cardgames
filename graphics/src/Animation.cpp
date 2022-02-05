#include "Animation.hpp"

#include <json/reader.h>
#include <iostream>  
#include <fstream>  

namespace cardgame::blackjack::view{

Animation::Animation(const std::string& textureFile,
                     const std::string& configFile)
  : mConfigFile(configFile)
  , mCurrentFrame(0)
{
  if (!mTexture.loadFromFile(textureFile))
  {
    //TODO: Now what?
  }
  mTexture.setSmooth(true);
  mSprite.setTexture(mTexture);

  Json::CharReaderBuilder rbuilder;
  rbuilder["collectComments"] = false;
  std::string errs;
  std::ifstream file(configFile);
  Json::Value root;
  bool ok = Json::parseFromStream(rbuilder, file, &root, &errs);
  mFramesCfg = root["frames"];
  setNextFrame();
}

void Animation::setPosition(float x, float y)
{
  mSprite.setPosition(x,y);
}

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if (mClock.getElapsedTime().asMilliseconds() > 30)
  {
    setNextFrame();
    mClock.restart();
  }
  
  target.draw(mSprite, states);
}

void Animation::setNextFrame() const
{
  const Json::Value frame = mFramesCfg[mCurrentFrame]["frame"];
  sf::IntRect rectSourceSprite(frame["x"].asInt(),
                               frame["y"].asInt(),
                               frame["w"].asInt(),
                               frame["h"].asInt());
  mSprite.setTextureRect(rectSourceSprite);  

  mCurrentFrame++;
  if(mCurrentFrame >= mFramesCfg.size())
  {
    mCurrentFrame = 0;
  }
}

}
