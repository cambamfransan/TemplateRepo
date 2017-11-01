#include <QtTest>
#include "ProtoFiles/addressbook.pb.h"

class ProtoFilesTest : public QObject
{
  Q_OBJECT

public:
  ProtoFilesTest();
  ~ProtoFilesTest();

  private slots:
  void initTestCase();
  void cleanupTestCase();
  void checkAddressBook();
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

void ProtoFilesTest::checkAddressBook()
{
//  tutorial::Person person;
//  person.set_email("cameron.frandsen1@gmail.com");
//  person.set_id(1);
//  person.set_name("Cameron Frandsen");

  //auto sString = person.SerializeAsString();
  //tutorial::Person returnedMsg;
  //returnedMsg.ParseFromString(sString);
//  QVERIFY(person.id() == 1);
//  QVERIFY(person.email() == "cameron.frandsen1@gmail.com");
 // QVERIFY(person.name() == "Cameron Frandsen");
}

QTEST_APPLESS_MAIN(ProtoFilesTest)

#include "ProtoFilesTestMain.moc"
