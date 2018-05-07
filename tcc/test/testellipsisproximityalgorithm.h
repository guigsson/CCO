#ifndef TESTELLIPSISPROXIMITYALGORITHM_H
#define TESTELLIPSISPROXIMITYALGORITHM_H

#include <QtTest/QtTest>
#include <QObject>
#include "utility/ellipsisproximityalgorithm.h"

class TestEllipsisProximityAlgorithm : public QObject
{
    Q_OBJECT

 private Q_SLOTS:
    void TestInBetweenCircleCenter();
    void TestInBetweenCircleOuter();
    void TestInBetweenCircleNotCollinear();
    void TestInBetweenCircleNotInBetween();
    void TestInBetweenEllipsisCenter();
    void TestInBetweenEllipsisOuter();
    void TestInBetweenEllipsisNotCollinear();
    void TestInBetweenEllipsisNotInBetween();

 private:
    EllipsisProximityAlgorithm proximity_algorithm;
};

#endif // TESTELLIPSISPROXIMITYALGORITHM_H
