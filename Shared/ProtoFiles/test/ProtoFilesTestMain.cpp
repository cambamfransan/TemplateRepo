#include <QtTest>
#include "ProtoFiles/ClueStartMsg.pb.h"
#include "ProtoFiles/Pending.pb.h"
#include "ProtoFiles/ReplyBattleshipMove.pb.h"
#include "ProtoFiles/ReplyBattleshipStart.pb.h"
#include "ProtoFiles/ReplyClueGuess.pb.h"
#include "ProtoFiles/ReplyClueMove.pb.h"
#include "ProtoFiles/ReplyBattleshipMove.pb.h"
#include "ProtoFiles/ReplyBattleshipStart.pb.h"
#include "ProtoFiles/ReplyClueGuess.pb.h"
#include "ProtoFiles/ReplyClueMove.pb.h"
#include "ProtoFiles/ReplyYahtzeeMove.pb.h"
#include "ProtoFiles/RequestClueGuess.pb.h"
#include "ProtoFiles/RequestClueMove.pb.h"
#include "ProtoFiles/RequestYahtzeeMove.pb.h"
#include "ProtoFiles/UpdateBattleshipMove.pb.h"
#include "ProtoFiles/UpdateClueGuess.pb.h"
#include "ProtoFiles/UpdateYahtzeeMove.pb.h"
#include "ProtoFiles/YahtzeeStartMsg.pb.h"
#include "ProtoFiles/MessageToSend.pb.h"

class ProtoFilesTest : public QObject
{
  Q_OBJECT

public:
  ProtoFilesTest();
  ~ProtoFilesTest();

  private slots:
  void initTestCase();
  void cleanupTestCase();
  void checkMsgId();
  void checkBasicMsg();
  void checkClueStartMsg();
  void checkPending();
  void checkReplyBattleshipMove();
  void checkReplyBattleshipStart();
  void checkReplyClueGuess();
  void checkReplyClueMove();
  void checkReplyYahtzeeMove();
  void checkRequestClueGuess();
  void checkRequestClueMove();
  void checkRequestYahtzeeMove();
  void checkUpdateBattleshipMove();
  void checkUpdateClueGuess();
  void checkUpdateYahtzeeMove();
  void checkYahtzeeStartMsg();
};

ProtoFilesTest::ProtoFilesTest()
{
}

ProtoFilesTest::~ProtoFilesTest()
{
}

void ProtoFilesTest::initTestCase()
{
}

void ProtoFilesTest::cleanupTestCase()
{
  google::protobuf::ShutdownProtobufLibrary();
}

void ProtoFilesTest::checkMsgId()
{
  msg::MessageToSend mToSend;
  msg::MessageId* msgId = new msg::MessageId();
  msgId->set_msgtype(10);
  msgId->set_attempt(22);
  msgId->set_convid(33);
  mToSend.set_allocated_msgid(msgId);
  mToSend.set_prototype(msg::ProtoType::MESSAGE_ID);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::MESSAGE_ID);
  QVERIFY(returnedMsg.msgid().msgtype() == 10);
  QVERIFY(returnedMsg.msgid().attempt() == 22);
  QVERIFY(returnedMsg.msgid().convid() == 33);
}

void ProtoFilesTest::checkBasicMsg()
{
  msg::MessageToSend mToSend;
  msg::BasicMsg* basicMsg = new msg::BasicMsg();
  basicMsg->set_serverid(20);
  basicMsg->set_clientid(33);
  mToSend.set_prototype(msg::ProtoType::BASIC_MSG);
  mToSend.set_allocated_basicmsg(basicMsg);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedBasicMsg;
  returnedBasicMsg.ParseFromString(sString);
  QVERIFY(returnedBasicMsg.prototype() == msg::ProtoType::BASIC_MSG);
  QVERIFY(returnedBasicMsg.basicmsg().serverid() == 20);
  QVERIFY(returnedBasicMsg.basicmsg().clientid() == 33);
}

void ProtoFilesTest::checkClueStartMsg()
{
  msg::MessageToSend mToSend;
  msg::ClueStartMsg* cStartMsg = new msg::ClueStartMsg();
  cStartMsg->add_orderofplayers(1);
  cStartMsg->add_orderofplayers(2);
  cStartMsg->add_orderofplayers(4);
  cStartMsg->add_orderofplayers(3);
  cStartMsg->add_availablecards(msg::Cards::SCARLET);
  cStartMsg->add_availablecards(msg::Cards::KNIFE);
  cStartMsg->add_availablecards(msg::Cards::BALLROOM);
  cStartMsg->add_availablecards(msg::Cards::GREEN);
  mToSend.set_allocated_cluestartmsg(cStartMsg);
  mToSend.set_prototype(msg::ProtoType::CLUE_START_MSG);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  returnedMsg.cluestartmsg();
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::CLUE_START_MSG);
  QVERIFY(returnedMsg.cluestartmsg().orderofplayers(0) == 1);
  QVERIFY(returnedMsg.cluestartmsg().orderofplayers(1) == 2);
  QVERIFY(returnedMsg.cluestartmsg().orderofplayers(2) == 4);
  QVERIFY(returnedMsg.cluestartmsg().orderofplayers(3) == 3);
  QVERIFY(returnedMsg.cluestartmsg().availablecards(0) == msg::Cards::SCARLET);
  QVERIFY(returnedMsg.cluestartmsg().availablecards(1) == msg::Cards::KNIFE);
  QVERIFY(returnedMsg.cluestartmsg().availablecards(2) == msg::Cards::BALLROOM);
  QVERIFY(returnedMsg.cluestartmsg().availablecards(3) == msg::Cards::GREEN);
}

void ProtoFilesTest::checkPending()
{
  msg::MessageToSend mToSend;
  msg::Pending* pendingMsg = new msg::Pending();
  pendingMsg->set_timeleft(18);
  mToSend.set_allocated_pending(pendingMsg);
  mToSend.set_prototype(msg::ProtoType::PENDING);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::PENDING);
  QVERIFY(returnedMsg.pending().timeleft() == 18);
}

void ProtoFilesTest::checkReplyBattleshipMove()
{
  msg::MessageToSend mToSend;
  msg::ReplyBattleshipMove* replyBattleshipMoveMsg = new msg::ReplyBattleshipMove();
  replyBattleshipMoveMsg->set_xcoor(18);
  replyBattleshipMoveMsg->set_ycoor(25);
  mToSend.set_allocated_replybattleshipmove(replyBattleshipMoveMsg);
  mToSend.set_prototype(msg::ProtoType::REPLY_BATTLESHIP_MOVE);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REPLY_BATTLESHIP_MOVE);
  QVERIFY(returnedMsg.replybattleshipmove().xcoor() == 18);
  QVERIFY(returnedMsg.replybattleshipmove().ycoor() == 25);
}

void ProtoFilesTest::checkReplyBattleshipStart()
{
  msg::MessageToSend mToSend;
  msg::ReplyBattleshipStart* replyBattleshipStartMsg = new msg::ReplyBattleshipStart();
  replyBattleshipStartMsg->add_xcoor(18);
  replyBattleshipStartMsg->add_xcoor(50);
  replyBattleshipStartMsg->add_xcoor(12);
  replyBattleshipStartMsg->add_xcoor(74);
  replyBattleshipStartMsg->add_ycoor(25);
  replyBattleshipStartMsg->add_ycoor(84);
  replyBattleshipStartMsg->add_ycoor(2);
  replyBattleshipStartMsg->add_ycoor(100);
  mToSend.set_allocated_replybattleshipstart(replyBattleshipStartMsg);
  mToSend.set_prototype(msg::ProtoType::REPLY_BATTLESHIP_START);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  auto xCoors = returnedMsg.replybattleshipstart().xcoor();
  auto yCoors = returnedMsg.replybattleshipstart().ycoor();
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REPLY_BATTLESHIP_START);
  QVERIFY(xCoors[0] == 18);
  QVERIFY(xCoors[1] == 50);
  QVERIFY(xCoors[2] == 12);
  QVERIFY(xCoors[3] == 74);
  QVERIFY(yCoors[0] == 25);
  QVERIFY(yCoors[1] == 84);
  QVERIFY(yCoors[2] == 2);
  QVERIFY(yCoors[3] == 100);
}

void ProtoFilesTest::checkReplyClueGuess()
{
  msg::MessageToSend mToSend;
  msg::ReplyClueGuess* replyClueGuessMsg = new msg::ReplyClueGuess();
  mToSend.set_allocated_replyclueguess(replyClueGuessMsg);
  mToSend.set_prototype(msg::ProtoType::REPLY_CLUE_GUESS);
  replyClueGuessMsg->set_card(msg::Cards::CONSERVATORY);  
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REPLY_CLUE_GUESS);
  QVERIFY(returnedMsg.replyclueguess().card() == msg::Cards::CONSERVATORY);
}

void ProtoFilesTest::checkReplyClueMove()
{
  msg::MessageToSend mToSend;
  msg::ReplyClueMove* replyClueMoveMsg = new msg::ReplyClueMove();
  replyClueMoveMsg->add_cards(msg::Cards::CANDLESTICK);
  replyClueMoveMsg->add_cards(msg::Cards::HALL);
  replyClueMoveMsg->add_cards(msg::Cards::CONSERVATORY);
  replyClueMoveMsg->set_iffinal(true);
  mToSend.set_allocated_replycluemove(replyClueMoveMsg);
  mToSend.set_prototype(msg::ProtoType::REPLY_CLUE_MOVE);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  auto cards = returnedMsg.replycluemove().cards();
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REPLY_CLUE_MOVE);
  QVERIFY(returnedMsg.replycluemove().iffinal() == true);
  QVERIFY(cards[0] == msg::Cards::CANDLESTICK);
  QVERIFY(cards[1] == msg::Cards::HALL);
  QVERIFY(cards[2] == msg::Cards::CONSERVATORY);
}

void ProtoFilesTest::checkReplyYahtzeeMove()
{
  msg::MessageToSend mToSend;
  msg::ReplyYahtzeeMove* replyYahtzeeMoveMsg = new msg::ReplyYahtzeeMove();
  replyYahtzeeMoveMsg->add_dicetokeep(3);
  replyYahtzeeMoveMsg->add_dicetokeep(3);
  replyYahtzeeMoveMsg->add_dicetokeep(3);
  replyYahtzeeMoveMsg->set_end(true);
  replyYahtzeeMoveMsg->set_itemoncard(5);
  mToSend.set_allocated_replyyahtzeemove(replyYahtzeeMoveMsg);
  mToSend.set_prototype(msg::ProtoType::REPLY_YAHTZEE_MOVE);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  auto dice = returnedMsg.replyyahtzeemove().dicetokeep();
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REPLY_YAHTZEE_MOVE);
  QVERIFY(dice[0] == 3);
  QVERIFY(dice[1] == 3);
  QVERIFY(dice[2] == 3);
  QVERIFY(returnedMsg.replyyahtzeemove().end() == true);
  QVERIFY(returnedMsg.replyyahtzeemove().itemoncard() == 5);
}

void ProtoFilesTest::checkRequestClueGuess()
{
  msg::MessageToSend mToSend;
  msg::RequestClueGuess* requestClueGuessMsg = new msg::RequestClueGuess();
  requestClueGuessMsg->add_cards(msg::Cards::STUDY);
  requestClueGuessMsg->add_cards(msg::Cards::ROPE);
  requestClueGuessMsg->add_cards(msg::Cards::WHITE);
  requestClueGuessMsg->set_guesser(4);
  mToSend.set_allocated_requestclueguess(requestClueGuessMsg);
  mToSend.set_prototype(msg::ProtoType::REQUEST_CLUE_GUESS);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  auto cards = returnedMsg.requestclueguess().cards();
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REQUEST_CLUE_GUESS);
  QVERIFY(cards[0] == msg::Cards::STUDY);
  QVERIFY(cards[1] == msg::Cards::ROPE);
  QVERIFY(cards[2] == msg::Cards::WHITE);
  QVERIFY(returnedMsg.requestclueguess().guesser() == 4);
}

void ProtoFilesTest::checkRequestClueMove()
{
  msg::MessageToSend mToSend;
  msg::RequestClueMove* requestClueMoveMsg = new msg::RequestClueMove();
  mToSend.set_allocated_requestcluemove(requestClueMoveMsg);
  mToSend.set_prototype(msg::ProtoType::REQUEST_CLUE_MOVE);
  requestClueMoveMsg->set_diceroll(6);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REQUEST_CLUE_MOVE);
  QVERIFY(returnedMsg.requestcluemove().diceroll() == 6);
}

void ProtoFilesTest::checkRequestYahtzeeMove()
{
  msg::MessageToSend mToSend;
  msg::RequestYahtzeeMove* requestYahtzeeMoveMsg = new msg::RequestYahtzeeMove();
  requestYahtzeeMoveMsg->add_dice(6);
  requestYahtzeeMoveMsg->add_dice(1);
  requestYahtzeeMoveMsg->add_dice(2);
  requestYahtzeeMoveMsg->add_dice(3);
  requestYahtzeeMoveMsg->add_dice(4);
  requestYahtzeeMoveMsg->set_diceroll(3);
  requestYahtzeeMoveMsg->set_playersid(2);
  mToSend.set_allocated_requestyahtzeemove(requestYahtzeeMoveMsg);
  mToSend.set_prototype(msg::ProtoType::REQUEST_YAHTZEE_MOVE);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  auto dice = returnedMsg.requestyahtzeemove().dice();
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::REQUEST_YAHTZEE_MOVE);
  QVERIFY(dice[0] == 6);
  QVERIFY(dice[1] == 1);
  QVERIFY(dice[2] == 2);
  QVERIFY(dice[3] == 3);
  QVERIFY(dice[4] == 4);
  QVERIFY(returnedMsg.requestyahtzeemove().diceroll() == 3);
  QVERIFY(returnedMsg.requestyahtzeemove().playersid() == 2);
}

void ProtoFilesTest::checkUpdateBattleshipMove()
{
  msg::MessageToSend mToSend;
  msg::UpdateBattleshipMove* updateBattleshipMoveMsg = new msg::UpdateBattleshipMove();
  updateBattleshipMoveMsg->set_ycoor(6);
  updateBattleshipMoveMsg->set_xcoor(10);
  updateBattleshipMoveMsg->set_hit(false);
  mToSend.set_allocated_updatebattleshipmove(updateBattleshipMoveMsg);
  mToSend.set_prototype(msg::ProtoType::UPDATE_BATTLESHIP_MOVE);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::UPDATE_BATTLESHIP_MOVE);
  QVERIFY(returnedMsg.updatebattleshipmove().xcoor() == 10);
  QVERIFY(returnedMsg.updatebattleshipmove().ycoor() == 6);
  QVERIFY(returnedMsg.updatebattleshipmove().hit() == false);
}

void ProtoFilesTest::checkUpdateClueGuess()
{
  msg::MessageToSend mToSend;
  msg::UpdateClueGuess* updateClueGuessMsg = new msg::UpdateClueGuess();
  updateClueGuessMsg->set_card(msg::Cards::UNKOWN);
  updateClueGuessMsg->set_playerid(2);
  mToSend.set_allocated_updateclueguess(updateClueGuessMsg);
  mToSend.set_prototype(msg::ProtoType::UPDATE_CLUE_GUESS);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(mToSend.prototype() == msg::ProtoType::UPDATE_CLUE_GUESS);
  QVERIFY(returnedMsg.updateclueguess().card() == msg::Cards::UNKOWN);
  QVERIFY(returnedMsg.updateclueguess().playerid() == 2);
}

void ProtoFilesTest::checkUpdateYahtzeeMove()
{
  msg::MessageToSend mToSend;
  msg::UpdateYahtzeeMove* pMsg = new msg::UpdateYahtzeeMove();
  pMsg->set_playerid(3);
  pMsg->set_score(38);
  pMsg->set_scorecarditem(4);
  mToSend.set_allocated_updateyahtzeemove(pMsg);
  mToSend.set_prototype(msg::ProtoType::UPDATE_YAHTZEE_MOVE);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.updateyahtzeemove().playerid() == 3);
  QVERIFY(returnedMsg.updateyahtzeemove().score() == 38);
  QVERIFY(returnedMsg.updateyahtzeemove().scorecarditem() == 4);
  QVERIFY(returnedMsg.prototype() == msg::ProtoType::UPDATE_YAHTZEE_MOVE);
}

void ProtoFilesTest::checkYahtzeeStartMsg()
{
  msg::MessageToSend mToSend;
  msg::YahtzeeStartMsg* yahtzeeStartMsg = new msg::YahtzeeStartMsg();
  yahtzeeStartMsg->add_orderofplayers(3);
  yahtzeeStartMsg->add_orderofplayers(1);
  yahtzeeStartMsg->add_orderofplayers(2);
  yahtzeeStartMsg->add_orderofplayers(4);
  mToSend.set_allocated_yahtzeestartmsg(yahtzeeStartMsg);
  mToSend.set_prototype(msg::ProtoType::YAHTZEE_START_MSG);
  auto sString = mToSend.SerializeAsString();
  msg::MessageToSend returnedMsg;
  returnedMsg.ParseFromString(sString);
  QVERIFY(returnedMsg.yahtzeestartmsg().orderofplayers(0) == 3);
  QVERIFY(returnedMsg.yahtzeestartmsg().orderofplayers(1) == 1);
  QVERIFY(returnedMsg.yahtzeestartmsg().orderofplayers(2) == 2);
  QVERIFY(returnedMsg.yahtzeestartmsg().orderofplayers(3) == 4);
}

QTEST_APPLESS_MAIN(ProtoFilesTest)

#include "ProtoFilesTestMain.moc"
