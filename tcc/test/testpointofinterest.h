#ifndef TESTPOINTOFINTEREST_H
#define TESTPOINTOFINTEREST_H

#include <QString>
#include <QtTest/QtTest>

#include "src/model/pointofinterest.h"

class TestPointOfInterest : public QObject
{
    Q_OBJECT

 private Q_SLOTS:
    void TestDistanceToManhattan();
    void TestDistanceToEuclidean();
};

#endif // TESTPOINTOFINTEREST_H
