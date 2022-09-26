#include "BlackjackConfig.hpp"

namespace cardgames::graphics::config
{

//TODO: this is just for testing before move on to loading yaml config files
BlackjackConfig::BlackjackConfig(std::filesystem::path configFilePath)
{
  mBlackjack.window = {"Blackjack", 2560,1440};

  mBlackjack.centerpiece.transform.position.x = 2560/2;
  mBlackjack.centerpiece.transform.position.y = 1440/2;
  mBlackjack.centerpiece.transform.scale.x = 1.0;
  mBlackjack.centerpiece.transform.scale.y = 1.0;
  mBlackjack.centerpiece.transform.angle = 0;
  mBlackjack.centerpiece.circle.shape.fillcolor = 0x00000000;
  mBlackjack.centerpiece.circle.shape.outlinecolor = 0x575555ff;
  mBlackjack.centerpiece.circle.shape.outline = 2;
  mBlackjack.centerpiece.circle.radius = 400;
  mBlackjack.centerpiece.circle.points = 900;
  mBlackjack.centerpiece.title.transform.position.x = 0;
  mBlackjack.centerpiece.title.transform.position.y = -100;
  mBlackjack.centerpiece.title.transform.scale.x = 1.0;
  mBlackjack.centerpiece.title.transform.scale.y = 1.0;
  mBlackjack.centerpiece.title.transform.angle = 0;
  mBlackjack.centerpiece.title.font = "halittany_badela.ttf";
  mBlackjack.centerpiece.title.size = 100;
  mBlackjack.centerpiece.title.fillcolor = 0x141414ff;
  mBlackjack.centerpiece.title.outlinecolor = 0xffffffff;
  mBlackjack.centerpiece.title.outline = 2;
  mBlackjack.centerpiece.title.style = { true, true, false, false};
  mBlackjack.centerpiece.title.alignment = config::TextAlignment::Center;
  mBlackjack.centerpiece.row1.transform.position.x = 0;
  mBlackjack.centerpiece.row1.transform.position.y = 0;
  mBlackjack.centerpiece.row1.transform.scale.x = 1.0;
  mBlackjack.centerpiece.row1.transform.scale.y = 1.0;
  mBlackjack.centerpiece.row1.transform.angle = 0;
  mBlackjack.centerpiece.row1.font = "mermaid.ttf";
  mBlackjack.centerpiece.row1.size = 50;
  mBlackjack.centerpiece.row1.fillcolor = 0x872222ff;
  mBlackjack.centerpiece.row1.outlinecolor = 0xffffffff;
  mBlackjack.centerpiece.row1.outline = 1;
  mBlackjack.centerpiece.row1.style = { false, true, false, false};
  mBlackjack.centerpiece.row1.alignment = config::TextAlignment::Center;
  mBlackjack.centerpiece.row2.transform.position.x = 0;
  mBlackjack.centerpiece.row2.transform.position.y = 60;
  mBlackjack.centerpiece.row2.transform.scale.x = 1.0;
  mBlackjack.centerpiece.row2.transform.scale.y = 1.0;
  mBlackjack.centerpiece.row2.transform.angle = 0;
  mBlackjack.centerpiece.row2.font = "mermaid.ttf";
  mBlackjack.centerpiece.row2.size = 30;
  mBlackjack.centerpiece.row2.fillcolor = 0xEBEBEBff;
  mBlackjack.centerpiece.row2.outlinecolor = 0x000000aa;
  mBlackjack.centerpiece.row2.outline = 1;
  mBlackjack.centerpiece.row2.style = { false, false, false, false};
  mBlackjack.centerpiece.row2.alignment = config::TextAlignment::Center;

  mBlackjack.players[0].hand.cardsOffset.x = 30;
  mBlackjack.players[0].hand.cardsOffset.y = 10;
  mBlackjack.players[0].hand.cardsScale.x = 0.3;
  mBlackjack.players[0].hand.cardsScale.y = 0.3;
  mBlackjack.players[0].hand.sumText.alignment = config::TextAlignment::Center;
  mBlackjack.players[0].hand.sumText.fillcolor = 0xff0000ff;
  mBlackjack.players[0].hand.sumText.font = "magic_retro.ttf";
  mBlackjack.players[0].hand.sumText.outline = 1;
  mBlackjack.players[0].hand.sumText.outlinecolor = 0xffffffff;
  mBlackjack.players[0].hand.sumText.size = 50;
  mBlackjack.players[0].hand.sumText.style = { false, false, false, false};
  mBlackjack.players[0].hand.sumText.transform.angle = 0;
  mBlackjack.players[0].hand.sumText.transform.position.x = 30;
  mBlackjack.players[0].hand.sumText.transform.position.y = -140;
  mBlackjack.players[0].hand.sumText.transform.scale.x = 1.0;
  mBlackjack.players[0].hand.sumText.transform.scale.y = 1.0;
  mBlackjack.players[0].hand.transform.angle = 0;
  mBlackjack.players[0].hand.transform.position.x = 0;
  mBlackjack.players[0].hand.transform.position.y = 100;
  mBlackjack.players[0].hand.transform.scale.x = 1.0;
  mBlackjack.players[0].hand.transform.scale.y = 1.0;
  mBlackjack.players[0].handsOffset.x = 400;
  mBlackjack.players[0].handsOffset.y = 0;
  mBlackjack.players[0].transform.angle = 90;
  mBlackjack.players[0].transform.position.x = 400;
  mBlackjack.players[0].transform.position.y = 500;
  mBlackjack.players[0].transform.scale.x = 1.0;
  mBlackjack.players[0].transform.scale.y = 1.0;
  
  mBlackjack.players[1].hand.cardsOffset.x = 30;
  mBlackjack.players[1].hand.cardsOffset.y = 10;
  mBlackjack.players[1].hand.cardsScale.x = 0.3;
  mBlackjack.players[1].hand.cardsScale.y = 0.3;
  mBlackjack.players[1].hand.sumText.alignment = config::TextAlignment::Center;
  mBlackjack.players[1].hand.sumText.fillcolor = 0xff0000ff;
  mBlackjack.players[1].hand.sumText.font = "magic_retro.ttf";
  mBlackjack.players[1].hand.sumText.outline = 1;
  mBlackjack.players[1].hand.sumText.outlinecolor = 0xffffffff;
  mBlackjack.players[1].hand.sumText.size = 50;
  mBlackjack.players[1].hand.sumText.style = { false, false, false, false};
  mBlackjack.players[1].hand.sumText.transform.angle = 0;
  mBlackjack.players[1].hand.sumText.transform.position.x = 30;
  mBlackjack.players[1].hand.sumText.transform.position.y = -140;
  mBlackjack.players[1].hand.sumText.transform.scale.x = 1.0;
  mBlackjack.players[1].hand.sumText.transform.scale.y = 1.0;
  mBlackjack.players[1].hand.transform.angle = 0;
  mBlackjack.players[1].hand.transform.position.x = 0;
  mBlackjack.players[1].hand.transform.position.y = 100;
  mBlackjack.players[1].hand.transform.scale.x = 1.0;
  mBlackjack.players[1].hand.transform.scale.y = 1.0;
  mBlackjack.players[1].handsOffset.x = 400;
  mBlackjack.players[1].handsOffset.y = 0;
  mBlackjack.players[1].transform.angle = 0;
  mBlackjack.players[1].transform.position.x = 1100;
  mBlackjack.players[1].transform.position.y = 1100;
  mBlackjack.players[1].transform.scale.x = 1.0;
  mBlackjack.players[1].transform.scale.y = 1.0;

  mBlackjack.players[2].hand.cardsOffset.x = 30;
  mBlackjack.players[2].hand.cardsOffset.y = 10;
  mBlackjack.players[2].hand.cardsScale.x = 0.3;
  mBlackjack.players[2].hand.cardsScale.y = 0.3;
  mBlackjack.players[2].hand.sumText.alignment = config::TextAlignment::Center;
  mBlackjack.players[2].hand.sumText.fillcolor = 0xff0000ff;
  mBlackjack.players[2].hand.sumText.font = "magic_retro.ttf";
  mBlackjack.players[2].hand.sumText.outline = 1;
  mBlackjack.players[2].hand.sumText.outlinecolor = 0xffffffff;
  mBlackjack.players[2].hand.sumText.size = 50;
  mBlackjack.players[2].hand.sumText.style = { false, false, false, false};
  mBlackjack.players[2].hand.sumText.transform.angle = 0;
  mBlackjack.players[2].hand.sumText.transform.position.x = 30;
  mBlackjack.players[2].hand.sumText.transform.position.y = -140;
  mBlackjack.players[2].hand.sumText.transform.scale.x = 1.0;
  mBlackjack.players[2].hand.sumText.transform.scale.y = 1.0;
  mBlackjack.players[2].hand.transform.angle = 0;
  mBlackjack.players[2].hand.transform.position.x = 0;
  mBlackjack.players[2].hand.transform.position.y = 100;
  mBlackjack.players[2].hand.transform.scale.x = 1.0;
  mBlackjack.players[2].hand.transform.scale.y = 1.0;
  mBlackjack.players[2].handsOffset.x = 400;
  mBlackjack.players[2].handsOffset.y = 0;
  mBlackjack.players[2].transform.angle = -90;
  mBlackjack.players[2].transform.position.x = 2260;
  mBlackjack.players[2].transform.position.y = 1000;
  mBlackjack.players[2].transform.scale.x = 1.0;
  mBlackjack.players[2].transform.scale.y = 1.0;

  mBlackjack.players[3].hand.cardsOffset.x = 30;
  mBlackjack.players[3].hand.cardsOffset.y = 10;
  mBlackjack.players[3].hand.cardsScale.x = 0.3;
  mBlackjack.players[3].hand.cardsScale.y = 0.3;
  mBlackjack.players[3].hand.sumText.alignment = config::TextAlignment::Center;
  mBlackjack.players[3].hand.sumText.fillcolor = 0xff0000ff;
  mBlackjack.players[3].hand.sumText.font = "magic_retro.ttf";
  mBlackjack.players[3].hand.sumText.outline = 1;
  mBlackjack.players[3].hand.sumText.outlinecolor = 0xffffffff;
  mBlackjack.players[3].hand.sumText.size = 50;
  mBlackjack.players[3].hand.sumText.style = { false, false, false, false};
  mBlackjack.players[3].hand.sumText.transform.angle = 0;
  mBlackjack.players[3].hand.sumText.transform.position.x = 30;
  mBlackjack.players[3].hand.sumText.transform.position.y = -140;
  mBlackjack.players[3].hand.sumText.transform.scale.x = 1.0;
  mBlackjack.players[3].hand.sumText.transform.scale.y = 1.0;
  mBlackjack.players[3].hand.transform.angle = 0;
  mBlackjack.players[3].hand.transform.position.x = 0;
  mBlackjack.players[3].hand.transform.position.y = 100;
  mBlackjack.players[3].hand.transform.scale.x = 1.0;
  mBlackjack.players[3].hand.transform.scale.y = 1.0;
  mBlackjack.players[3].handsOffset.x = 400;
  mBlackjack.players[3].handsOffset.y = 0;
  mBlackjack.players[3].transform.angle = 180;
  mBlackjack.players[3].transform.position.x = 1500;
  mBlackjack.players[3].transform.position.y = 300;
  mBlackjack.players[3].transform.scale.x = 1.0;
  mBlackjack.players[3].transform.scale.y = 1.0;

  mBlackjack.dealerHand.cardsOffset.x = 30;
  mBlackjack.dealerHand.cardsOffset.y = 10;
  mBlackjack.dealerHand.cardsScale.x = 0.3;
  mBlackjack.dealerHand.cardsScale.y = 0.3;
  mBlackjack.dealerHand.sumText.alignment = config::TextAlignment::Center;
  mBlackjack.dealerHand.sumText.fillcolor = 0xff0000ff;
  mBlackjack.dealerHand.sumText.font = "magic_retro.ttf";
  mBlackjack.dealerHand.sumText.outline = 1;
  mBlackjack.dealerHand.sumText.outlinecolor = 0xffffffff;
  mBlackjack.dealerHand.sumText.size = 50;
  mBlackjack.dealerHand.sumText.style = { false, false, false, false};
  mBlackjack.dealerHand.sumText.transform.angle = 0;
  mBlackjack.dealerHand.sumText.transform.position.x = 30;
  mBlackjack.dealerHand.sumText.transform.position.y = -140;
  mBlackjack.dealerHand.sumText.transform.scale.x = 1.0;
  mBlackjack.dealerHand.sumText.transform.scale.y = 1.0;
  mBlackjack.dealerHand.transform.angle = 0;
  mBlackjack.dealerHand.transform.position.x = 1200;
  mBlackjack.dealerHand.transform.position.y = 700;
  mBlackjack.dealerHand.transform.scale.x = 1.0;
  mBlackjack.dealerHand.transform.scale.y = 1.0;

}

const Blackjack& BlackjackConfig::GetConfig() const
{
  return mBlackjack;
}

}
