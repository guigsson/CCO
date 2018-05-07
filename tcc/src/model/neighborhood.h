#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H

#include <QList>
#include <QDateTime>
#include <QDate>

#include "user.h"
#include "pointofinterest.h"
#include "utility/graph.h"
#include "trajectory.h"

#define THEN QDateTime(QDate::fromJulianDay(0))
#define NOW QDateTime::currentDateTime()

class Neighborhood
{
public:
    Neighborhood(QList<std::shared_ptr<User>> users,
                 QList<std::shared_ptr<PointOfInterest>> pois, double max_dist, DistanceType dist_type);
    QList<std::shared_ptr<PointOfInterest>> GetVicinity(std::shared_ptr<PointOfInterest> poi);
    QList<std::shared_ptr<PointOfInterest>> GetSameTypeVicinity(
            std::shared_ptr<PointOfInterest> poi);
    Trajectory GetTrajectory(std::shared_ptr<User> user);
    Trajectory GetTrajectory(std::shared_ptr<User> user, const QDateTime& start,
                             const QDateTime& stop);
    std::shared_ptr<User> GetUserById(int id) const;
    std::shared_ptr<PointOfInterest> GetPOIById(const QString& id) const;

 private:
    QList<std::shared_ptr<User>> users_;
    QList<std::shared_ptr<PointOfInterest>> points_of_interest_;
    double max_dist_;
    Graph<std::shared_ptr<PointOfInterest>> vicinity_graph_;
};

#endif // NEIGHBORHOOD_H
