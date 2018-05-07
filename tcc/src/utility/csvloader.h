#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <QString>
#include <QMap>
#include <QList>
#include <memory>
#include <QPointF>

#include "model/user.h"
#include "model/pointofinterest.h"
#include "model/checkin.h"

struct CsvLine {
    int checkin_id;
    int tid;
    QPointF lat_lon;
    QDateTime date_time;
    WeekDay day;
    QString poi_foursquare_id;
    QString poi_name;
    Type poi_type;
    Price poi_price;
    double poi_rating;
    Weather weather;
};

class CsvLoader
{
 public:
    CsvLoader(const QString& filename);
    QList<std::shared_ptr<User>> GetUsers();
    QList<std::shared_ptr<PointOfInterest>> GetPointsOfInterest();

 private:
    QMap<int, std::shared_ptr<User>> users_;
    QMap<QString, std::shared_ptr<PointOfInterest>> points_of_interest_;
    QMap<int, std::shared_ptr<CheckIn>> checkins_;
    QList<CsvLine> lines_;
};

#endif // CSVLOADER_H
