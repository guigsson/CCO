#ifndef PROXIMITYALGORITHM_H
#define PROXIMITYALGORITHM_H

#include <QPointF>

class ProximityAlgorithm {
 public:
    virtual bool InBetween(const QPointF&p, const QPointF& p1, const QPointF& p2) const = 0;
};

#endif // PROXIMITYALGORITHM_H
