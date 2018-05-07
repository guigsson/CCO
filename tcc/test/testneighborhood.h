#ifndef TESTNEIGHBORHOOD_H
#define TESTNEIGHBORHOOD_H

#include <QObject>
#include <QtTest/QtTest>

#include <memory>

#include "src/model/checkin.h"
#include "src/model/neighborhood.h"
#include "src/model/pointofinterest.h"
#include "src/model/user.h"
#include "src/utility/csvloader.h"

class TestNeighborhood : public QObject
{
    Q_OBJECT
 public:
    TestNeighborhood();

 private Q_SLOTS:
    void TestGetUserById();
    void TestGetPOIById();
    void TestGetVicinity();
    void TestGetVicinityNoNeighbors();
    void TestGetSameTypeVicinity();
    void TestGetSameTypeVicinityNoSameTypeNeighbors();
    void TestGetSameTypeVicinityNoNeighbors();
    void TestGetTrajectory();

 private:
    CsvLoader loader;
    QList<std::shared_ptr<User>> users;
    QList<std::shared_ptr<PointOfInterest>> pois;
    std::shared_ptr<Neighborhood> neighborhood;
};

#endif // TESTNEIGHBORHOOD_H
