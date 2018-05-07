#include "csvloader.h"
#include <QFile>
#include <QStringList>
#include <QDebug>

CsvLoader::CsvLoader(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QStringList header;
        QString headerstr = file.readLine();
        header.append(headerstr.split(',', QString::SkipEmptyParts));

        QList<QStringList> lines;
        while (!file.atEnd()) {
            QStringList line;
            QString linestr = file.readLine();
            line << linestr.split(',', QString::SkipEmptyParts);
            if (line.size() == 11)
                lines.append(line);
        }
        int linenumber = -1;
        for (QStringList line : lines) {
            linenumber++;
            CsvLine c;
            c.checkin_id = line.at(0).toInt();
            c.tid = line.at(1).toInt();
            c.lat_lon = QPointF(line.at(2).split(' ').first().toFloat(),
                                       line.at(2).split(' ').last().toFloat());
            c.date_time = QDateTime::fromString(line.at(3));
            c.day = CheckIn::WeekdayFromString(line.at(4));
            c.poi_foursquare_id = line.at(5);
            c.poi_name = line.at(6);
            c.poi_type = PointOfInterest::TypeFromString(line.at(7));
            c.poi_price = static_cast<Price>(line.at(8).toInt());
            c.poi_rating = line.at(9).toDouble();
            c.weather = CheckIn::WeatherFromString(line.at(10));

            std::shared_ptr<User> user;
            if (users_.contains(c.tid)) {
                user = users_[c.tid];
            } else {
                user = std::make_shared<User>(c.tid);
                users_[c.tid] = user;
            }

            std::shared_ptr<PointOfInterest> poi;
            if (points_of_interest_.contains(c.poi_foursquare_id)) {
                poi = points_of_interest_[c.poi_foursquare_id];
            } else {
                poi = std::make_shared<PointOfInterest>(c.poi_foursquare_id,
                                                        c.lat_lon, c.poi_name,
                                                        c.poi_type, c.poi_price,
                                                        c.poi_rating);
                points_of_interest_[c.poi_foursquare_id] = poi;
            }
            std::shared_ptr<CheckIn> checkin =
                    std::make_shared<CheckIn>(c.checkin_id, c.date_time,
                                              c.day, c.weather, poi);
            user->AddCheckin(checkin);
        }
    }
}

QList<std::shared_ptr<User>> CsvLoader::GetUsers()
{
    return users_.values();
}

QList<std::shared_ptr<PointOfInterest> > CsvLoader::GetPointsOfInterest()
{
    return points_of_interest_.values();
}
