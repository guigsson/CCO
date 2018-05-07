#include "checkin.h"

CheckIn::CheckIn(int id, const QDateTime &time, WeekDay day, Weather weather,
                 std::shared_ptr<PointOfInterest> poi)
    : id_(id), time_(time), day_(day), weather_(weather), poi_(poi) {}

WeekDay CheckIn::WeekdayFromString(const QString &day)
{
    if (day.toLower() == "sunday")
        return SUNDAY;
    else if (day.toLower() == "monday")
        return MONDAY;
    else if (day.toLower() == "tuesday")
        return TUESDAY;
    else if (day.toLower() == "wednesday")
        return WEDNESDAY;
    else if (day.toLower() == "thursday")
        return THURSDAY;
    else if (day.toLower() == "friday")
        return FRIDAY;
    else if (day.toLower() == "saturday")
        return SATURDAY;
    return NOT_KNOWN;
}

const QString CheckIn::WeekdayToString(WeekDay day)
{
    switch (day) {
    case SUNDAY: return "Sunday";
    case MONDAY: return "Monday";
    case TUESDAY: return "Tuesday";
    case WEDNESDAY: return "Wednesday";
    case THURSDAY: return "Thursday";
    case FRIDAY: return "Friday";
    case SATURDAY: return "Saturday";
    default: case NOT_KNOWN: return "INVALID";
    }
}

Weather CheckIn::WeatherFromString(const QString &weather)
{
    if (weather.toLower() == "clear")
        return CLEAR;
    else if (weather.toLower() == "clouds")
        return CLOUDS;
    else if (weather.toLower() == "fog")
        return FOG;
    else if (weather.toLower() == "rain")
        return RAIN;
    else if (weather.toLower() == "snow")
        return SNOW;
    return UNKNOWN;
}

const QString CheckIn::WeatherToString(Weather weather)
{
    switch (weather) {
    case CLEAR: return "Clear";
    case CLOUDS: return "Clouds";
    case FOG: return "Fog";
    case RAIN: return "Rain";
    case SNOW: return "Snow";
    default: case UNKNOWN: return "INVALID";
    }
}
