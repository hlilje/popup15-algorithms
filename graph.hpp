/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <queue>
#include <vector>


template<typename T>
struct Graph
{
    Graph(const std::size_t);

    // _nodes[i][j] = neighbour j of i
    std::vector<std::vector<long>> _nodes;
    // _nodes[i][j] = weight for edge i -> j
    std::vector<std::vector<T>> _weights;
};

template<typename T>
struct PairComp
{
    bool operator ()(const std::pair<T, long>&,
                     const std::pair<T, long>&);
};


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
 * @param graph:               Graph struct.
 * @param start_times:         Start times for train departures.
 * @param departure_intervals: Intervals when trains depature.
 * @param start:               Index for start node.
 * @return:                    A pair of parent/distances vectors.
 */
template<typename T>
std::pair<std::vector<long>, std::vector<T>>
shortest_path_time(const Graph<T>&, const std::vector<std::vector<long>>&,
                   const std::vector<std::vector<long>>&, const long);

#include "graph.cpp"

#endif
