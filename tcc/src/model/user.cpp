#include "user.h"

User::User(int id)
    : id_(id)
{}

void User::AddCheckin(std::shared_ptr<CheckIn> checkin)
{
    checkins_.append(checkin);
}

int User::VisitsTo(std::shared_ptr<PointOfInterest> poi)
{
    int visits = 0;
    for (auto checkin : checkins_) {
        if (checkin->poi_ == poi) {
            visits++;
        }
    }
    return visits;
}

QList<std::shared_ptr<CheckIn> > User::GetCheckIns()
{
    return checkins_;
}

int User::id() const
{
    return id_;
}

void User::setId(int id)
{
    id_ = id;
}

std::shared_ptr<PointOfInterest> User::home() const
{
    return home_;
}

void User::setHome(const std::shared_ptr<PointOfInterest> &home)
{
    home_ = home;
}

QList<std::shared_ptr<PointOfInterest> > User::GetTrajectory(const QDateTime &start,
                                                             const QDateTime &end)
{
    QList<std::shared_ptr<PointOfInterest>> trajectory;
    for (auto checkin : checkins_) {
        if (checkin->time_ >= start && checkin->time_ <= end) {
            trajectory.append(checkin->poi_);
        }
        if (checkin->time_ > end) {
            break;
        }
    }
    return trajectory;
}
