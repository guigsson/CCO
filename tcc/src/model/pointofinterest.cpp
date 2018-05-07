#include "pointofinterest.h"
#include <QLineF>
#include <QtMath>

PointOfInterest::PointOfInterest(const QString &id, const QPointF &coordinate,
                                 const QString &name, Type type, Price price,
                                 double rating)
        : id_(id), coordinate_(coordinate), name_(name), type_(type),
          price_(price), rating_(rating),
          proximity_algorithm_(std::make_shared<EllipsisProximityAlgorithm>()) {}

qreal PointOfInterest::DistanceTo(const PointOfInterest &other, DistanceType dist_type) const {
    return DistanceTo(other.coordinate(), dist_type);
}

qreal PointOfInterest::DistanceTo(const QPointF &other, DistanceType dist_type) const {
    qreal distance = -1;
    switch (dist_type) {
    case MANHATTAN:
        distance = qAbs(coordinate_.x() - other.x()) +
                   qAbs(coordinate_.y() - other.y());
        break;
    case EUCLIDEAN:
        distance =  qSqrt(qPow(coordinate_.x() - other.x(), 2) +
                          qPow(coordinate_.y() - other.y(), 2));
        break;
    }
    return distance;
}

double PointOfInterest::DistanceX(const PointOfInterest &other) const
{
    return abs(coordinate_.x() - other.coordinate_.x());
}

double PointOfInterest::DistanceY(const PointOfInterest &other) const
{
    return abs(coordinate_.y() - other.coordinate_.y());
}

bool PointOfInterest::InBetween(const PointOfInterest &one, const PointOfInterest &other) const
{
    return proximity_algorithm_->InBetween(coordinate(), one.coordinate(),
                                           other.coordinate());
}

void PointOfInterest::SetProximityAlgorithm(std::shared_ptr<ProximityAlgorithm> p)
{
    proximity_algorithm_ = p;
}

QString PointOfInterest::toString()
{
    QString coordinatestr = "(" + QString::number(coordinate().x()) +
                            "," + QString::number(coordinate().y()) + ")";
    QString typestr = TypeToString(type_);
    return "{" + name_ + " ; " + coordinatestr + " ; " + typestr + "}";
}

QString PointOfInterest::id() const
{
    return id_;
}

void PointOfInterest::setId(const QString &id)
{
    id_ = id;
}

QPointF PointOfInterest::coordinate() const
{
    return coordinate_;
}

void PointOfInterest::setCoordinate(const QPointF &coordinate)
{
    coordinate_ = coordinate;
}

QString PointOfInterest::name() const
{
    return name_;
}

void PointOfInterest::setName(const QString &name)
{
    name_ = name;
}

Type PointOfInterest::type() const
{
    return type_;
}

void PointOfInterest::setType(const Type &type)
{
    type_ = type;
}

Price PointOfInterest::price() const
{
    return price_;
}

void PointOfInterest::setPrice(const Price &price)
{
    price_ = price;
}

double PointOfInterest::rating() const
{
    return rating_;
}

void PointOfInterest::setRating(double rating)
{
    rating_ = rating;
}

bool PointOfInterest::operator<(const PointOfInterest &other) const
{
    return id_ < other.id_;
}

Type PointOfInterest::TypeFromString(const QString &type)
{
    if (type.toLower() == "arts & entertainment")
        return ART_AND_ENTERTAINMENT;
    else if (type.toLower() == "college & university")
        return COLLEGE_AND_UNIVERSITY;
    else if (type.toLower() == "event")
        return EVENT;
    else if (type.toLower() == "food")
        return FOOD;
    else if (type.toLower() == "nightlife spot")
        return NIGHTLIFE_SPOT;
    else if (type.toLower() == "outdoors & recreation")
        return OUTDOORS_AND_RECREATION;
    else if (type.toLower() == "professional & other places")
        return PROFESSIONAL_AND_OTHER;
    else if (type.toLower() == "residence")
        return RESIDENCE;
    else if (type.toLower() == "shop & service")
        return SHOP_AND_SERVICE;
    else if (type.toLower() == "travel & transport")
        return TRAVEL_AND_TRANSPORT;
    return NONE;
}

const QString PointOfInterest::TypeToString(Type type)
{
    switch (type) {
    case ART_AND_ENTERTAINMENT: return "Arts & Entertainment";
    case COLLEGE_AND_UNIVERSITY: return "College & University";
    case EVENT: return "Event";
    case FOOD: return "Food";
    case NIGHTLIFE_SPOT: return "Nightlife Spot";
    case OUTDOORS_AND_RECREATION: return "Outdoors & Recreation";
    case PROFESSIONAL_AND_OTHER: return "Professional & Other Places";
    case RESIDENCE: return "Residence";
    case SHOP_AND_SERVICE: return "Shop & Service";
    case TRAVEL_AND_TRANSPORT: return "Travel & Transport";
    case NONE: return "INVALID";
    }
}
