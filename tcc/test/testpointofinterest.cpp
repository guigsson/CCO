#include "test/testpointofinterest.h"

#include <QtTest>
#include <QObject>
#include <QString>

#include "model/pointofinterest.h"

//class TestPointOfInterest : public QObject
//{
//    Q_OBJECT
// public:
//    TestPointOfInterest();

// private Q_SLOTS:
//    void TestDistanceToManhattan();
//    void TestDistanceToEuclidean();
//};

void TestPointOfInterest::TestDistanceToManhattan() {


    PointOfInterest p1("0", QPointF(1, 1), "p1", Type::ART_AND_ENTERTAINMENT);
    PointOfInterest p2("0", QPointF(2, 2), "p2", Type::ART_AND_ENTERTAINMENT);

    QVERIFY(p1.DistanceTo(p2) == 2);
}

void TestPointOfInterest::TestDistanceToEuclidean() {


    PointOfInterest p1("0", QPointF(0, 0), "p1", Type::ART_AND_ENTERTAINMENT);
    PointOfInterest p2("0", QPointF(3, 4), "p2", Type::ART_AND_ENTERTAINMENT);

    QVERIFY(p1.DistanceTo(p2, DistanceType::EUCLIDEAN) == 5);
}
