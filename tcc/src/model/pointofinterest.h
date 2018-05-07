#ifndef POINTOFINTEREST_H
#define POINTOFINTEREST_H

#include <QString>
#include <QPointF>
#include <QHash>
#include <memory>

#include "utility/proximityalgorithm.h"
#include "utility/ellipsisproximityalgorithm.h"

enum Type {
    ART_AND_ENTERTAINMENT,
    COLLEGE_AND_UNIVERSITY,
    EVENT,
    FOOD,
    NIGHTLIFE_SPOT,
    OUTDOORS_AND_RECREATION,
    PROFESSIONAL_AND_OTHER,
    RESIDENCE,
    SHOP_AND_SERVICE,
    TRAVEL_AND_TRANSPORT,
    NONE
};

enum Price {
    UNDEFINED,
    VERY_CHEAP,
    CHEAP,
    INTERMEDIATE,
    EXPENSIVE,
    VERY_EXPENSIVE
};

enum DistanceType {
    MANHATTAN,
    EUCLIDEAN
};

class PointOfInterest
{
 public:
    PointOfInterest(const QString& id, const QPointF &coordinate, const QString& name,
                    Type type, Price price = UNDEFINED, double rating = -1);

    qreal DistanceTo(const PointOfInterest& other, DistanceType dist_type = MANHATTAN) const;
    qreal DistanceTo(const QPointF& point, DistanceType dist_type = MANHATTAN) const;
    double DistanceX(const PointOfInterest& other) const;
    double DistanceY(const PointOfInterest& other) const;
    bool InBetween(const PointOfInterest& one, const PointOfInterest& other) const;
    void SetProximityAlgorithm(std::shared_ptr<ProximityAlgorithm> p);
    QString toString();

    QString id() const;
    void setId(const QString &id);

    QPointF coordinate() const;
    void setCoordinate(const QPointF &coordinate);

    QString name() const;
    void setName(const QString &name);

    Type type() const;
    void setType(const Type &type);

    Price price() const;
    void setPrice(const Price &price);

    double rating() const;
    void setRating(double rating);

    inline bool operator<(const PointOfInterest &other) const;

    static Type TypeFromString(const QString& type);
    static const QString TypeToString(Type type);

private:
    QString id_;
    QPointF coordinate_;
    QString name_;
    Type type_;
    Price price_;
    double rating_;
    std::shared_ptr<ProximityAlgorithm> proximity_algorithm_;
    static qreal ellipsis_ab_rate_;
    static qreal ellipsis_outer_rate_;
};

#endif // POINTOFINTEREST_H
