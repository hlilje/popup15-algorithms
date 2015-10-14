/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH_H
#define GRAPH_H

#include "union_find.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
#include <vector>


template<typename T>
struct Edge
{
    const T weight;
    const long from, to;
    const long first_time;
    const long between_time;

    /*
     * @param weight:       Edge weight.
     * @param from, to:     Nodes connected.
     * @param first_time:   Edge becomes available.
     * @param between_time: Time in between.
     */
    Edge(const T, const long, const long, const long, const long);
};

template<typename T>
struct Graph
{
    // Vector to lists of out edges, 0-based index = node
    std::vector<std::vector<Edge<T>*>> out_edges;

    /*
     * @param num_nodes: The number of nodes in the graph.
     */
    Graph(const std::size_t);
};

template<typename T>
struct PairComp
{
    bool operator ()(const std::pair<T, long>&,
                     const std::pair<T, long>&);
};


/*
 * Find the minimum spanning tree of the given graph.
 *
 * @param graph: The graph to find the tree for.
 * @return     : All the edges of the minimum spanning tree.
 */
template<typename T>
std::set<Edge<T>*> mst(const Graph<T>&);

/*
 * Find the shortest paths between the start node and all other nodes using
 * Dijkstra's algorithm.
 *
 * @param graph: Graph struct.
 * @param start: Index for start node.
 * @return:      A pair of parent/distances vectors.
 */
template<typename T>
std::pair<std::vector<long>, std::vector<T>>
shortest_path(const Graph<T>&, const long);

/*
 * Find the shortest paths between the start node and all other nodes using
 * Dijkstra's algorithm, where edges switch between available and
 * unavailable.
 *
 * @param graph: Graph struct.
 * @param start: Index for start node.
 * @return:      A pair of parent/distances vectors.
 */
template<typename T>
std::pair<std::vector<long>, std::vector<T>>
shortest_path_time(const Graph<T>&, const long);

#include "graph.cpp"

#endif
