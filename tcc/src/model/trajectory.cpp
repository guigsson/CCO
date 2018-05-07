#include "trajectory.h"

Trajectory::Trajectory(std::shared_ptr<User> user, std::shared_ptr<PointOfInterest> start,
                       std::shared_ptr<PointOfInterest> end,
                       QList<std::shared_ptr<PointOfInterest> > trajectory,
                       QDateTime start_time, QDateTime end_time)
        : user_(user), start_(start), end_(end), trajectory_(trajectory),
          start_time_(start_time), end_time_(end_time)
{}
