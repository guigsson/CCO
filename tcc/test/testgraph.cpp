#include "test/testgraph.h"

#include <QObject>
#include <QtTest>

#include "utility/graph.h"

#include <memory>

//class TestGraph : public QObject
//{
//    Q_OBJECT
// public:
//    TestGraph() : QObject(nullptr) {}
//    virtual ~TestGraph() {}

// private Q_SLOTS:
//    void TestGetVertice();
//    void TestAddEdgeNonExistentVertice();
//    void TestGetEdge();
//    void TestGetAdjacentEdgesNoAdjacentEdges();
//    void TestGetAdjacentEdges();
//};

void TestGraph::TestGetVertice()
{
    Graph<int> graph;
    graph.AddVertice(10);

    QVERIFY(graph.GetVertices().contains(10));
}

void TestGraph::TestAddEdgeNonExistentVertice()
{
    Graph<int> graph;
    graph.AddEdge(1, 2);

    QVERIFY(graph.GetVertices().contains(1));
    QVERIFY(graph.GetVertices().contains(2));
}

void TestGraph::TestGetEdge()
{
    Graph<int> graph;
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 4);

    QVERIFY(graph.GetEdges()[1].size() == 3);
    QVERIFY(graph.GetEdges()[1].contains(2));
    QVERIFY(graph.GetEdges()[1].contains(3));
    QVERIFY(graph.GetEdges()[1].contains(4));

    QVERIFY(graph.GetEdges()[2].size() == 2);
    QVERIFY(graph.GetEdges()[2].contains(1));
    QVERIFY(graph.GetEdges()[2].contains(4));

    QVERIFY(graph.GetEdges()[3].size() == 1);
    QVERIFY(graph.GetEdges()[3].contains(1));

    QVERIFY(graph.GetEdges()[4].size() == 2);
    QVERIFY(graph.GetEdges()[4].contains(1));
    QVERIFY(graph.GetEdges()[4].contains(2));
}

void TestGraph::TestGetAdjacentEdges()
{
    Graph<int> graph;
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 4);

    QVERIFY(graph.GetAdjacentVertices(1).size() == 3);
    QVERIFY(graph.GetAdjacentVertices(1).contains(2));
    QVERIFY(graph.GetAdjacentVertices(1).contains(3));
    QVERIFY(graph.GetAdjacentVertices(1).contains(4));

    QVERIFY(graph.GetAdjacentVertices(2).size() == 2);
    QVERIFY(graph.GetAdjacentVertices(2).contains(1));
    QVERIFY(graph.GetAdjacentVertices(2).contains(4));

    QVERIFY(graph.GetAdjacentVertices(3).size() == 1);
    QVERIFY(graph.GetAdjacentVertices(3).contains(1));

    QVERIFY(graph.GetAdjacentVertices(4).size() == 2);
    QVERIFY(graph.GetAdjacentVertices(4).contains(1));
    QVERIFY(graph.GetAdjacentVertices(4).contains(2));
}

void TestGraph::TestGetAdjacentEdgesNoAdjacentEdges()
{
    Graph<int> graph;
    graph.AddVertice(3);

    QVERIFY(graph.GetAdjacentVertices(3).size() == 0);
}
