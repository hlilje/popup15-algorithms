/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH
#define GRAPH

#include "graph.hpp"

typedef std::vector<long> long_vec;
template<typename T>
using t_vec = std::vector<T>;


template<typename T>
Graph<T>::Graph(const std::size_t num_nodes) :
    _nodes(std::vector<long_vec>(num_nodes)),
    _weights(std::vector<t_vec<T>>(num_nodes, t_vec<T>(num_nodes))) { }


template<typename T>
std::pair<long_vec, t_vec<T>> shortest_path(Graph<T>& graph, const long start)
{
    std::pair<long_vec, t_vec<T>> res;

    return res;
}

#endif
