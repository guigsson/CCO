#ifndef TESTGRAPH_H
#define TESTGRAPH_H

#include <QObject>
#include <QtTest/QtTest>

#include <memory>

class TestGraph : public QObject
{
    Q_OBJECT
 private Q_SLOTS:
    void TestGetVertice();
    void TestAddEdgeNonExistentVertice();
    void TestGetEdge();
    void TestGetAdjacentEdgesNoAdjacentEdges();
    void TestGetAdjacentEdges();
};

#endif // TESTGRAPH_H
