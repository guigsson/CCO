#include "test/testneighborhood.h"

#include <QObject>
#include <QtTest>
#include <QDateTime>
#include <QList>

#include <memory>

#include "model/checkin.h"
#include "model/neighborhood.h"
#include "model/pointofinterest.h"
#include "model/user.h"
#include "utility/csvloader.h"

//class TestNeighborhood : public QObject
//{
//    Q_OBJECT
//public:
//    TestNeighborhood();
//private slots:
//    void TestGetUserById();
//    void TestGetPOIById();
//    void TestGetVicinity();
//    void TestGetVicinityNoNeighbors();
//    void TestGetSameTypeVicinity();
//    void TestGetSameTypeVicinityNoSameTypeNeighbors();
//    void TestGetSameTypeVicinityNoNeighbors();
//    void TestGetTrajectory();

// private:
//    CsvLoader loader;
//    QList<std::shared_ptr<User>> users;
//    QList<std::shared_ptr<PointOfInterest>> pois;
//    std::shared_ptr<Neighborhood> neighborhood;
//};

TestNeighborhood::TestNeighborhood() : loader("resources/tuesday.csv")
{
    users = loader.GetUsers();
    pois = loader.GetPointsOfInterest();
    neighborhood = std::make_shared<Neighborhood>(users, pois, 1.8, DistanceType::EUCLIDEAN);
}

void TestNeighborhood::TestGetUserById()
{
    auto user = users.at(0);
    auto user1 = neighborhood->GetUserById(84);
    auto user2 = neighborhood->GetUserById(734);

    QVERIFY(user1.get() == user.get());
    QVERIFY(user2.get() != user.get());
}

void TestNeighborhood::TestGetPOIById()
{
    auto poi1 = pois.at(0);
    auto poi2 = pois.at(1);
    auto poi = neighborhood->GetPOIById("3fd66200f964a5200ae91ee3");
    QVERIFY(poi1.get() == poi.get());
    QVERIFY(poi2.get() != poi.get());
}

void TestNeighborhood::TestGetVicinity()
{
    auto poi = neighborhood->GetPOIById("4de45622c65b7a3e21485ecf");
    auto neighbors = neighborhood->GetVicinity(poi);

    QVERIFY(neighbors.size() == 8);
    QVERIFY(neighbors.contains(neighborhood->GetPOIById("4c2c49f38abca5930e850120")));
}

void TestNeighborhood::TestGetVicinityNoNeighbors()
{
    auto poi = neighborhood->GetPOIById("4a663f7cf964a52046c81fe3");
    auto neighbors = neighborhood->GetVicinity(poi);

    QVERIFY(neighbors.size() == 0);
}

void TestNeighborhood::TestGetSameTypeVicinity()
{
    auto poi = neighborhood->GetPOIById("4de45622c65b7a3e21485ecf");
    auto neighbors = neighborhood->GetSameTypeVicinity(poi);

    QVERIFY(neighbors.size() == 1);
    QVERIFY(neighbors.contains(neighborhood->GetPOIById("4df53b7bd4c01ff6b2f262ec")));
}

void TestNeighborhood::TestGetSameTypeVicinityNoSameTypeNeighbors()
{
    auto poi = neighborhood->GetPOIById("3fd66200f964a520dbe31ee3");
    auto neighbors = neighborhood->GetSameTypeVicinity(poi);

    QVERIFY(neighbors.size() == 0);
}

void TestNeighborhood::TestGetSameTypeVicinityNoNeighbors()
{
    auto poi = neighborhood->GetPOIById("4a663f7cf964a52046c81fe3");
    auto neighbors = neighborhood->GetSameTypeVicinity(poi);

    QVERIFY(neighbors.size() == 0);
}

void TestNeighborhood::TestGetTrajectory()
{
    auto user = neighborhood->GetUserById(734);
    auto start = QDateTime(QDate::fromJulianDay(0));
    auto stop = QDateTime::currentDateTime();
    auto trajectory = neighborhood->GetTrajectory(user, start, stop);

    QVERIFY(trajectory.trajectory_.size() == 3);
    QVERIFY(trajectory.start_ == neighborhood->GetPOIById("4df53b7bd4c01ff6b2f262ec"));
    QVERIFY(trajectory.end_ == neighborhood->GetPOIById("4b983023f964a520a13235e3"));
}
