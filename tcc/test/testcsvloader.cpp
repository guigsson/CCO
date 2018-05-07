#include "testcsvloader.h"

#include <QObject>
#include <QtTest>

#include <memory>

#include "utility/csvloader.h"
#include "model/checkin.h"
#include "model/pointofinterest.h"
#include "model/user.h"

//class TestCsvLoader : public QObject
//{
//    Q_OBJECT

// public:
//    TestCsvLoader();

// private Q_SLOTS:
//    void TestLoader();
//};

void TestCsvLoader::TestLoader()
{
    CsvLoader loader("resources/testloader.csv");

    auto users = loader.GetUsers();
    QVERIFY(users.size() == 1);
    QVERIFY(users.at(0)->id() == 70);

    auto pois = loader.GetPointsOfInterest();
    QVERIFY(pois.size() == 4);
    QVERIFY(pois.at(0)->id() == "439c437bf964a520f02b1fe3");

    auto user_checkins = users.at(0)->GetCheckIns();
    QVERIFY(user_checkins.size() == 5);
    QVERIFY(user_checkins.at(0)->id_ == 341937);
}
