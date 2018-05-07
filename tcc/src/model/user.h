#ifndef USER_H
#define USER_H

#include <QList>
#include <memory>

#include "checkin.h"
#include "pointofinterest.h"

class User
{
 public:
    User(int id);
    void AddCheckin(std::shared_ptr<CheckIn> checkin);
    QList<std::shared_ptr<PointOfInterest>> GetTrajectory(const QDateTime& start,
                                                         const QDateTime& end);
    int VisitsTo(std::shared_ptr<PointOfInterest> poi);
    QList<std::shared_ptr<CheckIn>> GetCheckIns();

    int id() const;
    void setId(int id);

    std::shared_ptr<PointOfInterest> home() const;
    void setHome(const std::shared_ptr<PointOfInterest> &home);

private:
    int id_;
    QList<std::shared_ptr<CheckIn>> checkins_;
    std::shared_ptr<PointOfInterest> home_;
};

#endif // USER_H
