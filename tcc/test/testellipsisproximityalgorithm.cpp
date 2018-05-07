#include "test/testellipsisproximityalgorithm.h"

#include <QtTest/QtTest>
#include <QObject>
#include <QPointF>

#include "utility/ellipsisproximityalgorithm.h"

//class TestEllipsisProximityAlgorithm : public QObject
//{
//    Q_OBJECT

// public:
//    TestEllipsisProximityAlgorithm();

// private Q_SLOTS:
//    void TestInBetweenCircleCenter();
//    void TestInBetweenCircleOuter();
//    void TestInBetweenCircleNotCollinear();
//    void TestInBetweenCircleNotInBetween();
//    void TestInBetweenEllipsisCenter();
//    void TestInBetweenEllipsisOuter();
//    void TestInBetweenEllipsisNotCollinear();
//    void TestInBetweenEllipsisNotInBetween();

// private:
//    EllipsisProximityAlgorithm proximity_algorithm;
//};

void TestEllipsisProximityAlgorithm::TestInBetweenCircleCenter()
{
    QPointF p1(0, 0);
    QPointF p2(2, 2);
    QPointF p(1, 1);

    proximity_algorithm.SetEllipsisRates(1, 1);

    QVERIFY(proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenCircleOuter()
{
    QPointF p1(0, 0);
    QPointF p2(2, 0);
    QPointF p(2.9, 0);

    proximity_algorithm.SetEllipsisRates(1, 2);

    QVERIFY(proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenCircleNotCollinear()
{
    QPointF p1(0, 0);
    QPointF p2(2, 2);
    QPointF p(2, 0);

    proximity_algorithm.SetEllipsisRates(1, 1);

    QVERIFY(proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenCircleNotInBetween()
{
    QPointF p1(0, 0);
    QPointF p2(2, 2);
    QPointF p(3, 3);

    proximity_algorithm.SetEllipsisRates(1, 1);

    QVERIFY(!proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenEllipsisCenter()
{
    QPointF p1(0, 0);
    QPointF p2(2, 2);
    QPointF p(1, 1);

    proximity_algorithm.SetEllipsisRates(0.5, 1);

    QVERIFY(proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenEllipsisOuter()
{
    QPointF p1(0, 0);
    QPointF p2(2, 0);
    QPointF p(3, 0);

    proximity_algorithm.SetEllipsisRates(0.5, 2);

    QVERIFY(proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenEllipsisNotCollinear()
{
    QPointF p1(0, 0);
    QPointF p2(2, 2);
    QPointF p(1.2, 1.2);

    proximity_algorithm.SetEllipsisRates(0.5, 1);

    QVERIFY(proximity_algorithm.InBetween(p, p1, p2));
}

void TestEllipsisProximityAlgorithm::TestInBetweenEllipsisNotInBetween()
{
    QPointF p1(0, 0);
    QPointF p2(2, 2);
    QPointF p(3, 3);

    proximity_algorithm.SetEllipsisRates(0.5, 1);

    QVERIFY(!proximity_algorithm.InBetween(p, p1, p2));
}
