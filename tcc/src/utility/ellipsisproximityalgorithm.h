#ifndef ELLIPSISPROXIMITYALGORITHM_H
#define ELLIPSISPROXIMITYALGORITHM_H

#include "utility/proximityalgorithm.h"

#define ELLIPSIS_A_B_RATE 0.3
#define ELLIPSIS_OUTER_DIST_RATE 1.1

class EllipsisProximityAlgorithm : public ProximityAlgorithm
{
 public:
    EllipsisProximityAlgorithm();
    bool InBetween(const QPointF&p, const QPointF& p1, const QPointF& p2) const override;
    void SetEllipsisRates(qreal ab_rate, qreal outer_rate);
    void SetEllipsisABRate(qreal ab_rate);
    void SetEllipsisOuterRate(qreal outer_rate);

 private:
    qreal ellipsis_ab_rate_;
    qreal ellipsis_outer_rate_;
};

#endif // ELLIPSISPROXIMITYALGORITHM_H
