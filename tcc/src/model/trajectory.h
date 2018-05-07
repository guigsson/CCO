#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <QDateTime>
#include <QList>

#include "user.h"
#include "pointofinterest.h"

struct Trajectory
{
    Trajectory(std::shared_ptr<User> user,
    std::shared_ptr<PointOfInterest> start,
    std::shared_ptr<PointOfInterest> end,
    QList<std::shared_ptr<PointOfInterest>> trajectory,
    QDateTime start_time,
    QDateTime end_time);

    std::shared_ptr<User> user_;
    std::shared_ptr<PointOfInterest> start_;
    std::shared_ptr<PointOfInterest> end_;
    QList<std::shared_ptr<PointOfInterest>> trajectory_;
    QDateTime start_time_;
    QDateTime end_time_;
};

#endif // TRAJECTORY_H
