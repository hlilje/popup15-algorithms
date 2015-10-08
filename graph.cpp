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
    std::set<std::pair<T, long>, PairComp<T>> active;
    std::vector<int> status(num_nodes, UNSEEN);
    std::vector<T> dist(num_nodes, INF);
    std::vector<long> parents(num_nodes);

    dist[start] = 0; // Not generic
    status[start] = DONE;

    // Initialise all neighbours of start node
    for (auto const& neighbour : graph._nodes[start])
    {
        active.insert(std::pair<T, long>(dist[neighbour], neighbour));
        status[neighbour] = PROCESSING;
        dist[neighbour] = graph._weights[start][neighbour];
        parents[neighbour] = start;
    }

    while (active.size() > 0)
    {
        // Find cheapest active node
        std::pair<T, long> cheapest_pair = *active.begin();
        long cheapest_node = cheapest_pair.second;

        active.erase(active.begin());
        status[cheapest_node] = DONE;

        // Check if neighbours of cheapest node has changed
        for (auto const& node : graph._nodes[cheapest_node])
        {
            T new_dist = graph._weights[cheapest_node][node] +
                         dist[cheapest_node];
            if (new_dist < dist[node])
            {
                parents[node] = cheapest_node;
                if (status[node] == PROCESSING)
                {
                    auto it = std::find_if(active.begin(), active.end(),
                        [&](const std::pair<T, long>& val) {
                            return val.first == dist[node] &&
                                   val.second == node; });
                    active.erase(it);
                }
                active.insert(std::pair<T, long>(new_dist, node));
                status[node] = PROCESSING;
                dist[node] = new_dist;
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dist);
}


#endif
