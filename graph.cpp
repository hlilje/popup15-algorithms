/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH
#define GRAPH

#include "graph.hpp"

#define INF std::numeric_limits<T>::max()
using long_vec = std::vector<long>;
template<typename T>
using edge_vec = std::vector<Edge<T>*>;
template<typename T>
using t_vec = std::vector<T>;


template<typename T>
Edge<T>::Edge(const T weight, const long from, const long to,
     const long first_time, const long between_time) :
    weight(weight), from(from), to(to),
    first_time(first_time), between_time(between_time) { }

template<typename T>
Graph<T>::Graph(const std::size_t num_nodes) :
    out_edges(std::vector<edge_vec<T>>(num_nodes)) {}

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
    auto num_nodes = graph.out_edges.size();
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
        for (const auto& edge : graph.out_edges[cheapest_node])
        {
            // Distance through cheapest node
            long next_node = edge->to;
            T new_dist = edge->weight + dist[cheapest_node];
            if (new_dist < dist[next_node])
            {
                parents[next_node] = cheapest_node;
                // NOTE: Incorrect, but faster on Kattis
                active.emplace(std::pair<T, long>(dist[next_node], next_node));
                dist[next_node] = new_dist;
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dist);
}

template<typename T>
std::pair<long_vec, t_vec<T>> shortest_path_time(const Graph<T>& graph,
                                                 const long start)
{
    auto num_nodes = graph.out_edges.size();
    std::priority_queue<std::pair<T, long>, std::vector<std::pair<T, long>>,
                        PairComp<T>> active;
    std::vector<T> time(num_nodes, INF);
    std::vector<long> parents(num_nodes);

    time[start] = 0; // Not generic

    active.emplace(std::pair<T, long>(time[start], start));

    while (!active.empty())
    {
        // Find cheapest active node
        long cheapest_node = active.top().second;
        active.pop();

        // Check if neighbours of cheapest node has changed
        for (const auto& edge : graph.out_edges[cheapest_node])
        {
            long next_node    = edge->to;
            long t_0          = edge->first_time;
            long P            = edge->between_time;
            long arrival_time = time[cheapest_node];
            long train_time   = arrival_time - t_0;
            long penalty      = 0;
            if (train_time >= 0) // First train has left
            {
                if (P == 0) // Only one train departure
                {
                    penalty = INF;
                }
                else // Find next departure
                {
                    long t = train_time / P;     // Number of departures
                    penalty = (t + 1) * P + t_0; // Next departure
                    penalty -= arrival_time;
                }
            }
            else // Take first departure
            {
                penalty = -train_time;
            }
            // Distance through cheapest node
            T new_time = edge->weight + arrival_time + penalty;
            if (new_time < time[next_node])
            {
                parents[next_node] = cheapest_node;
                time[next_node] = new_time;
                active.emplace(std::pair<T, long>(new_time, next_node));
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, time);
}

#endif
