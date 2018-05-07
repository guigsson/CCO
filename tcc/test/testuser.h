#ifndef TESTUSER_H
#define TESTUSER_H

#include <QObject>
#include <QtTest/QtTest>

class TestUser : public QObject
{
    Q_OBJECT
 private Q_SLOTS:
    void TestVisitsToNoCheckins();
    void TestVisitsToNoVisits();
    void TestVisitsTo();
    void TestGetTrajectoryNoCheckins();
    void TestGetTrajectory();
    void TestGetTrajectoryOutsideTimeInterval();
};

#endif // TESTUSER_H
