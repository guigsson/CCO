#include <QCoreApplication>

#include <QDebug>
#include "utility/csvloader.h"
#include "model/neighborhood.h"
#include "model/user.h"
#include "model/pointofinterest.h"
#include "model/checkin.h"
#include <iostream>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << QDir::currentPath().toStdString().c_str() << std::endl;
    CsvLoader loader("resources/checkins_foursquare_50.csv");
    QList<std::shared_ptr<User>> users = loader.GetUsers();
    QList<std::shared_ptr<PointOfInterest>> pois = loader.GetPointsOfInterest();

    Neighborhood neighborhood(users, pois, 0.05, DistanceType::MANHATTAN);
    auto poi = pois.at(0);
    auto neighbors = neighborhood.GetSameTypeVicinity(poi);
    std::cout << poi->toString().toStdString().c_str() << std::endl;
    int i = 0;
    for (auto neighbor : neighbors) {
        std::cout << i++ << std::endl;
        std::cout << neighbor->toString().toStdString().c_str() << std::endl;
        std::cout << neighbor->DistanceTo(*poi.get()) << std::endl;
    }

    return a.exec();
}
