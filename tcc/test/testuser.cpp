#include "test/testuser.h"

#include <QObject>
#include <QtTest>

#include <QPointF>
#include <QDebug>

#include <memory>

#include "model/checkin.h"
#include "model/pointofinterest.h"
#include "model/user.h"
#include "model/trajectory.h"

//class TestUser : public QObject
//{
//    Q_OBJECT
// public:
//    TestUser();

// private Q_SLOTS:
//    void TestVisitsToNoCheckins();
//    void TestVisitsToNoVisits();
//    void TestVisitsTo();
//    void TestGetTrajectoryNoCheckins();
//    void TestGetTrajectory();
//    void TestGetTrajectoryOutsideTimeInterval();
//};

void TestUser::TestVisitsToNoCheckins()
{
    std::shared_ptr<User> user = std::make_shared<User>(0);
    std::shared_ptr<PointOfInterest> poi =
            std::make_shared<PointOfInterest>("0", QPointF(0, 0), "p", Type::EVENT);

    QVERIFY(user->VisitsTo(poi) == 0);
}

void TestUser::TestVisitsToNoVisits()
{
    std::shared_ptr<User> user = std::make_shared<User>(0);
    std::shared_ptr<PointOfInterest> poi1 =
            std::make_shared<PointOfInterest>("1", QPointF(0, 0), "poi1", Type::EVENT);
    std::shared_ptr<PointOfInterest> poi2 =
            std::make_shared<PointOfInterest>("2", QPointF(0, 0), "poi2", Type::EVENT);
    std::shared_ptr<CheckIn> checkin =
            std::make_shared<CheckIn>(0, QDateTime::currentDateTime(),
                                      WeekDay::SATURDAY, Weather::CLEAR, poi1);
    user->AddCheckin(checkin);
    QVERIFY(user->VisitsTo(poi2) == 0);
}

void TestUser::TestVisitsTo()
{
    std::shared_ptr<User> user = std::make_shared<User>(0);
    std::shared_ptr<PointOfInterest> poi1 =
            std::make_shared<PointOfInterest>("1", QPointF(0, 0), "poi1", Type::EVENT);
    std::shared_ptr<CheckIn> checkin =
            std::make_shared<CheckIn>(0, QDateTime::currentDateTime(),
                                      WeekDay::SATURDAY, Weather::CLEAR, poi1);
    user->AddCheckin(checkin);
    QVERIFY(user->VisitsTo(poi1) == 1);
}

void TestUser::TestGetTrajectoryNoCheckins()
{
    QDateTime before = QDateTime::currentDateTime();
    std::shared_ptr<User> user = std::make_shared<User>(0);
    QDateTime after = QDateTime::currentDateTime();

    auto trajectory = user->GetTrajectory(before, after);
    QVERIFY(trajectory.size() == 0);
}

void TestUser::TestGetTrajectory()
{
    QDateTime before = QDateTime::currentDateTime();
    std::shared_ptr<User> user = std::make_shared<User>(0);
    std::shared_ptr<PointOfInterest> poi1 =
            std::make_shared<PointOfInterest>("1", QPointF(0, 0), "poi1", Type::EVENT);
    std::shared_ptr<PointOfInterest> poi2 =
            std::make_shared<PointOfInterest>("2", QPointF(0, 0), "poi2", Type::EVENT);
    std::shared_ptr<PointOfInterest> poi3 =
            std::make_shared<PointOfInterest>("3", QPointF(0, 0), "poi3", Type::EVENT);
    std::shared_ptr<CheckIn> checkin1 =
            std::make_shared<CheckIn>(1, QDateTime::currentDateTime(),
                                      WeekDay::SATURDAY, Weather::CLEAR, poi1);
    std::shared_ptr<CheckIn> checkin2 =
            std::make_shared<CheckIn>(2, QDateTime::currentDateTime(),
                                      WeekDay::SATURDAY, Weather::CLEAR, poi2);
    std::shared_ptr<CheckIn> checkin3 =
            std::make_shared<CheckIn>(3, QDateTime::currentDateTime(),
                                      WeekDay::SATURDAY, Weather::CLEAR, poi3);
    QDateTime after = QDateTime::currentDateTime();
    user->AddCheckin(checkin1);
    user->AddCheckin(checkin2);
    user->AddCheckin(checkin3);

    auto trajectory = user->GetTrajectory(before, after);
    QVERIFY(trajectory.at(0)->id() == "1");
    QVERIFY(trajectory.at(1)->id() == "2");
    QVERIFY(trajectory.at(2)->id() == "3");
}

void TestUser::TestGetTrajectoryOutsideTimeInterval()
{
    std::shared_ptr<User> user = std::make_shared<User>(0);
    std::shared_ptr<PointOfInterest> poi1 =
            std::make_shared<PointOfInterest>("1", QPointF(0, 0), "poi1", Type::EVENT);
    std::shared_ptr<CheckIn> checkin1 =
            std::make_shared<CheckIn>(1, QDateTime::currentDateTime(),
                                      WeekDay::SATURDAY, Weather::CLEAR, poi1);
    QTest::qSleep(10);
    QDateTime before = QDateTime::currentDateTime();
    QDateTime after = QDateTime::currentDateTime();
    user->AddCheckin(checkin1);

    auto trajectory = user->GetTrajectory(before, after);
    QVERIFY(trajectory.size() == 0);
}
