/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>


template<typename T>
struct Graph
{
    Graph(const std::size_t);

    std::vector<std::vector<long>> _nodes;
    std::vector<std::vector<T>> _weights;
};


template<typename T>
std::pair<std::vector<long>, std::vector<T>> shortest_path(Graph<T>&, const long);

#include "graph.cpp"

#endif
