#include "ellipsisproximityalgorithm.h"
#include <QLineF>
#include <QtMath>

EllipsisProximityAlgorithm::EllipsisProximityAlgorithm()
        : ellipsis_ab_rate_(ELLIPSIS_A_B_RATE),
          ellipsis_outer_rate_(ELLIPSIS_OUTER_DIST_RATE) {
}

bool EllipsisProximityAlgorithm::InBetween(const QPointF &p, const QPointF &p1, const QPointF &p2) const
{
    QPointF center(p1.x() + p2.x() / 2,
                   p1.y() + p2.y() / 2);
    QLineF axis(p1, p2);
    qreal angle = qDegreesToRadians(axis.angle());
    qreal m = tan(angle);
    qreal h = center.x();
    qreal k = center.y();
    qreal a = sqrt(pow(p1.x() - center.x(), 2) +
                   pow(p1.y() - center.y(), 2)) * ellipsis_outer_rate_;
    qreal b = a * ellipsis_ab_rate_;
    qreal x = p.x();
    qreal y = p.y();
    return pow(m * y + x - h - m * k, 2) / ((1 + pow(m, 2)) * pow(a, 2)) +
            pow(y - m * x + m * h - k, 2) / ((1 + pow(m, 2)) * pow(b, 2)) <= 1;
}

void EllipsisProximityAlgorithm::SetEllipsisRates(qreal ab_rate, qreal outer_rate)
{
    SetEllipsisABRate(ab_rate);
    SetEllipsisOuterRate(outer_rate);
}

void EllipsisProximityAlgorithm::SetEllipsisABRate(qreal ab_rate)
{
    if (ab_rate > 1) ellipsis_ab_rate_ = 1;
    else if (ab_rate <= 0) ellipsis_ab_rate_ = 0.00000001;
    else ellipsis_ab_rate_ = ab_rate;
}

void EllipsisProximityAlgorithm::SetEllipsisOuterRate(qreal outer_rate)
{
    if (outer_rate < 1) ellipsis_outer_rate_ = 1;
    else ellipsis_outer_rate_ = outer_rate;
}
