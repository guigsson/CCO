#include "neighborhood.h"
#include <QDebug>

Neighborhood::Neighborhood(QList<std::shared_ptr<User>> users,
                           QList<std::shared_ptr<PointOfInterest>> pois, double max_dist,
                           DistanceType dist_type)
        : users_(users), points_of_interest_(pois), max_dist_(max_dist) {
    if (pois.size() > 0) {
        for (int i = 0; i < points_of_interest_.size(); i++) {
            for (int j = i + 1; j < points_of_interest_.size(); j++) {
                if (points_of_interest_.at(i)->
                        DistanceTo(*points_of_interest_.at(j).get(), dist_type) <= max_dist) {
                    vicinity_graph_.AddEdge(points_of_interest_[i], points_of_interest_[j]);
                }
            }
        }
    }
}

QList<std::shared_ptr<PointOfInterest> > Neighborhood::GetVicinity(
        std::shared_ptr<PointOfInterest> poi)
{
    return vicinity_graph_.GetAdjacentVertices(poi);
}

QList<std::shared_ptr<PointOfInterest> > Neighborhood::GetSameTypeVicinity(
        std::shared_ptr<PointOfInterest> poi)
{
    QList<std::shared_ptr<PointOfInterest>> adjacents(
                vicinity_graph_.GetAdjacentVertices(poi));
    QList<std::shared_ptr<PointOfInterest>> same_type;
    for (auto adjacent : adjacents) {
        if (poi->type() == adjacent->type()) {
            same_type.append(adjacent);
        }
    }
    return same_type;
}

Trajectory Neighborhood::GetTrajectory(std::shared_ptr<User> user)
{
    return GetTrajectory(user, THEN, NOW);
}

Trajectory Neighborhood::GetTrajectory(std::shared_ptr<User> user, const QDateTime &start, const QDateTime &stop)
{
    QList<std::shared_ptr<PointOfInterest>> pois(user->GetTrajectory(start, stop));
    return Trajectory(user, pois.first(), pois.last(), pois,
                      user->GetCheckIns().first()->time_, user->GetCheckIns().last()->time_);
}

std::shared_ptr<User> Neighborhood::GetUserById(int id) const
{
    if (users_.size() == 0) return nullptr;
    for (auto user : users_) {
        if (user->id() == id) {
            return user;
        }
    }
    return nullptr;
}

std::shared_ptr<PointOfInterest> Neighborhood::GetPOIById(const QString &id) const
{
    if (points_of_interest_.size() == 0) return nullptr;
    for (auto poi : points_of_interest_) {
        if (poi->id() == id) {
            return poi;
        }
    }
    return nullptr;
}
