#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
#include <QMap>

template <typename T> class Graph
{
 public:
    Graph();
    void AddVertice(T vertice);
    void AddEdge(T v1, T v2);

    QList<T> GetVertices();
    QList<T> GetAdjacentVertices(T v);
    QMap<T, QList<T>> GetEdges();

 private:
    QList<T> vertices_;
    QMap<T, QList<T>> edges_;
};

template<typename T>
Graph<T>::Graph()
{}

template<typename T>
void Graph<T>::AddVertice(T vertice)
{
    if (vertices_.contains(vertice)) return;
    vertices_.append(vertice);
}

template<typename T>
void Graph<T>::AddEdge(T v1, T v2)
{
    AddVertice(v1);
    AddVertice(v2);
    edges_[v1].append(v2);
    edges_[v2].append(v1);
}

template<typename T>
QList<T> Graph<T>::GetVertices()
{
    return vertices_;
}

template<typename T>
QList<T> Graph<T>::GetAdjacentVertices(T v)
{
    if (!vertices_.contains(v)) return QList<T>();
    return edges_[v];
}

template<typename T>
QMap<T, QList<T> > Graph<T>::GetEdges()
{
    return edges_;
}

#endif // GRAPH_H
