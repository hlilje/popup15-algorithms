/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH
#define GRAPH

#include "graph.hpp"

#define INF std::numeric_limits<T>::max()
enum {UNSEEN, PROCESSING, DONE};
typedef std::vector<long> long_vec;
template<typename T>
using t_vec = std::vector<T>;


template<typename T>
Graph<T>::Graph(const std::size_t num_nodes) :
    _nodes(std::vector<long_vec>(num_nodes)),
    _weights(std::vector<t_vec<T>>(num_nodes, t_vec<T>(num_nodes, INF))) { }


template<typename T>
std::pair<long_vec, t_vec<T>> shortest_path(const Graph<T>& graph,
                                            const long start)
{
    auto num_nodes = graph._nodes.size();
    std::vector<long> active;
    std::vector<int> status(num_nodes, UNSEEN);
    std::vector<T> dist(num_nodes, INF);
    std::vector<long> parents(num_nodes);

    dist[start] = 0; // Not generic
    status[start] = PROCESSING;

    // Initialise all neighbours of start node
    for (auto const& neighbour : graph._nodes[start])
    {
        active.push_back(neighbour);
        status[neighbour] = PROCESSING;
        dist[neighbour] = graph._weights[start][neighbour];
        parents[neighbour] = start;
    }

    while (active.size() > 0)
    {
        long cheapest_ix = -1;
        long cheapest_node = -1;
        T cheapest_dist = INF;

        // Find cheapest active node
        for (long i = 0; i < (long) active.size(); ++i)
        {
            long node = active[i];
            if (dist[node] < cheapest_dist)
            {
                cheapest_ix = i;
                cheapest_node = node;
                cheapest_dist = dist[node];
            }
        }

        assert(cheapest_ix != -1);
        active.erase(active.begin() + cheapest_ix);
        status[cheapest_node] = DONE;

        // Check if neighbours of cheapest node has changed
        for (auto const& node : graph._nodes[cheapest_node])
        {
            if (status[node] != DONE)
            {
                T new_dist = graph._weights[cheapest_node][node] +
                             dist[cheapest_node];
                if (new_dist < dist[node])
                {
                    dist[node] = new_dist;
                    parents[node] = cheapest_node;
                    if (status[node] == UNSEEN)
                        active.push_back(node);
                    status[node] = PROCESSING;
                }
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dist);
}


#endif
