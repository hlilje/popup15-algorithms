/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH
#define GRAPH

#include "graph.hpp"

#define INF std::numeric_limits<T>::max()
enum {UNSEEN, PROCESSING, DONE};
using long_vec = std::vector<long>;
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
    if (a.first < b.first)
        return true;
    else if ((a.second == b.second) && (a.first < b.first))
        return true;
    else
        return false;
}


template<typename T>
std::pair<long_vec, t_vec<T>> shortest_path(const Graph<T>& graph,
                                            const long start)
{
    auto num_nodes = graph._nodes.size();
    std::set<std::pair<T, long>, PairComp<T>> active;
    /* std::vector<int> status(num_nodes, UNSEEN); */
    std::vector<T> dist(num_nodes, INF);
    std::vector<long> parents(num_nodes);

    dist[start] = 0; // Not generic
    /* status[start] = DONE; */

    active.insert(std::pair<T, long>(dist[start], start));

    while (!active.empty())
    {
        // Find cheapest active node
        long cheapest_node = active.begin()->second;

        active.erase(active.begin());
        /* status[cheapest_node] = DONE; */

        // Check if neighbours of cheapest node has changed
        for (auto const& node : graph._nodes[cheapest_node])
        {
            // Distance through cheapest node
            T new_dist = graph._weights[cheapest_node][node] +
                         dist[cheapest_node];
            if (new_dist < dist[node])
            {
                parents[node] = cheapest_node;
                /* if (status[node] == PROCESSING) */
                active.erase(std::pair<T, long>(dist[node], node));
                active.insert(std::pair<T, long>(new_dist, node));
                /* status[node] = PROCESSING; */
                dist[node] = new_dist;
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dist);
}


#endif
