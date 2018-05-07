#ifndef CHECKIN_H
#define CHECKIN_H

#include <QDateTime>
#include <memory>
#include "pointofinterest.h"

enum WeekDay {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    NOT_KNOWN
};

enum Weather {
    UNKNOWN,
    CLEAR,
    CLOUDS,
    FOG,
    RAIN,
    SNOW
};

struct CheckIn
{
    CheckIn(int id, const QDateTime& time, WeekDay day, Weather weather,
            std::shared_ptr<PointOfInterest> poi);
    int id_;
    QDateTime time_;
    WeekDay day_;
    Weather weather_;
    std::shared_ptr<PointOfInterest> poi_;

    static WeekDay WeekdayFromString(const QString& day);
    static const QString WeekdayToString(WeekDay day);
    static Weather WeatherFromString(const QString& weather);
    static const QString WeatherToString(Weather weather);
};

#endif // CHECKIN_H
