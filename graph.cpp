/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH
#define GRAPH

#include "graph.hpp"

#define INF std::numeric_limits<T>::max()
using long_vec = std::vector<long>;
using long_mat = std::vector<std::vector<long>>;
template<typename T>
using t_vec = std::vector<T>;


template<typename T>
Graph<T>::Graph(const std::size_t num_nodes) :
    _nodes(std::vector<long_vec>(num_nodes)),
    _weights(std::vector<t_vec<T>>(num_nodes, t_vec<T>(num_nodes, INF))) { }

template<typename T>
bool PairComp<T>::operator()(const std::pair<T, long>& a,
                             const std::pair<T, long>& b)
{
    return a.first < b.first;
}


template<typename T>
std::pair<long_vec, t_vec<T>> shortest_path(const Graph<T>& graph,
                                            const long start)
{
    auto num_nodes = graph._nodes.size();
    std::priority_queue<std::pair<T, long>, std::vector<std::pair<T, long>>,
                        PairComp<T>> active;
    std::vector<T> dist(num_nodes, INF);
    std::vector<long> parents(num_nodes);

    dist[start] = 0; // Not generic

    active.emplace(std::pair<T, long>(dist[start], start));

    while (!active.empty())
    {
        // Find cheapest active node
        long cheapest_node = active.top().second;
        active.pop();

        // Check if neighbours of cheapest node has changed
        for (const auto& node : graph._nodes[cheapest_node])
        {
            // Distance through cheapest node
            T new_dist = graph._weights[cheapest_node][node] +
                         dist[cheapest_node];
            if (new_dist < dist[node])
            {
                parents[node] = cheapest_node;
                active.emplace(std::pair<T, long>(dist[node], node));
                dist[node] = new_dist;
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dist);
}

template<typename T>
std::pair<long_vec, t_vec<T>> shortest_path_time(
        const Graph<T>& graph,
        const long_mat& start_times,
        const long_mat& departure_intervals,
        const long start)
{
    auto num_nodes = graph._nodes.size();
    std::priority_queue<std::pair<T, long>, std::vector<std::pair<T, long>>,
                        PairComp<T>> active;
    std::vector<T> dist(num_nodes, INF);
    std::vector<long> parents(num_nodes);

    dist[start] = 0; // Not generic

    active.emplace(std::pair<T, long>(dist[start], start));

    while (!active.empty())
    {
        // Find cheapest active node
        long cheapest_node = active.top().second;
        active.pop();

        // Check if neighbours of cheapest node has changed
        for (const auto& node : graph._nodes[cheapest_node])
        {
            // Distance through cheapest node
            T new_dist = graph._weights[cheapest_node][node] +
                         dist[cheapest_node];
            if (new_dist < dist[node])
            {
                parents[node] = cheapest_node;
                active.emplace(std::pair<T, long>(dist[node], node));
                dist[node] = new_dist;
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dist);
}

#endif
