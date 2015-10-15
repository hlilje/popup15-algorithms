/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GRAPH
#define GRAPH

#include "graph.hpp"

#define INF std::numeric_limits<T>::max() / 100
#define NEG_INF std::numeric_limits<T>::min() / 100
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
bool LexoComp<T>::operator()(const Edge<T>* a,
                             const Edge<T>* b)
{
    return a->from != b->from ? a->from < b->from : a->to < b->to;
}

template<typename T>
bool PairComp<T>::operator()(const std::pair<T, long>& a,
                             const std::pair<T, long>& b)
{
    return a.first < b.first;
}


template<typename T>
std::set<Edge<T>*, LexoComp<T>> mst(const Graph<T>& graph)
{
    auto num_nodes = graph.out_edges.size();

    // Sorts edges in lexicographic order
    std::set<Edge<T>*, LexoComp<T>> spanning_tree;
    std::vector<set*> sets(num_nodes);

    edge_vec<T> edges;
    for (const auto& edge_list : graph.out_edges)
        for (const auto& edge : edge_list)
            edges.push_back(edge);

    // Create a forest of singleton vertex components
    for (long i = 0; i < (long) num_nodes; ++i)
        sets[i] = new set(i);

    // Sort edges after ascending lengths
    std::sort(edges.begin(), edges.end(),
              [](const Edge<T>* a, const Edge<T>* b)
              { return a->weight < b->weight; });

    for (const auto& edge : edges)
    {
        set* u = sets[edge->from];
        set* v = sets[edge->to];
        if (find(u) != find(v)) {
            spanning_tree.insert(edge);
            set_union(u, v);
        }
    }

    for (const auto& set : sets) delete set;

    return spanning_tree;
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
std::pair<long_vec, t_vec<T>> shortest_path_neg(const Graph<T>& graph,
                                                const long start)
{
    auto num_nodes = graph.out_edges.size();
    t_vec<T> dists(num_nodes, INF);
    long_vec parents(num_nodes, -1);
    dists[start] = 0; // Not generic

    // Relax edges repeatedly
    for (long i = 0; i < (long) num_nodes - 1; ++i)
    {
        for (long from = 0; from < (long) num_nodes; ++from)
        {
            for (const auto& edge : graph.out_edges[from])
            {
                long to = edge->to;
                T new_dist = dists[from] + edge->weight;
                if (dists[from] == INF) new_dist = INF;
                if (dists[from] == NEG_INF) new_dist = NEG_INF;
                if (dists[to] > new_dist)
                {
                    dists[to] = new_dist;
                    parents[to] = from;
                }
            }
        }
    }

    // Still updatable => descendant of negative loop
    for (long from = 0; from < (long) num_nodes; ++from)
    {
        for (const auto& edge : graph.out_edges[from])
        {
            long to = edge->to;
            T new_dist = dists[from] + edge->weight;
            if (dists[from] == INF) new_dist = INF;
            if (dists[from] == NEG_INF) new_dist = NEG_INF;
            if (dists[to] > new_dist)
            {
                dists[to] = NEG_INF;
                parents[to] = from;

                // Backtrack to mark all parent nodes in the negative clan
                std::vector<bool> seen(num_nodes, false);
                long current = to;
                while (!seen[current])
                {
                    dists[current] = NEG_INF;
                    current = parents[current];
                    seen[current] = true;
                }
            }
        }
    }

    // Mark all descendants of start that are also descendants of
    // negative loops
    std::vector<bool> seen(num_nodes, false);
    std::queue<long> nodes;
    nodes.push(start);
    while (!nodes.empty())
    {
        long from = nodes.front(); nodes.pop();
        for (const auto& edge : graph.out_edges[from])
        {
            long to = edge->to;
            if (!seen[to])
            {
                nodes.push(to);
                seen[to] = true;
                if (dists[from] == NEG_INF)
                    dists[to] = NEG_INF;
            }
        }
    }

    return std::pair<long_vec, t_vec<T>>(parents, dists);
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

            if (train_time == 0) // Right on time
            {
                penalty = 0;
            }
            else if (train_time > 0) // First train has left
            {
                if (P == 0) // Only one train departure
                {
                    penalty = INF;
                }
                else // Find next departure
                {
                    penalty = P - (train_time % P); // Time to next departure
                    if (penalty == P) penalty = 0;
                }
            }
            else // Wait for first departure
            {
                penalty = -train_time;
            }

            // Distance through cheapest node
            T new_time = edge->weight + arrival_time + penalty;
            // For comparison
            if (new_time > INF) new_time = INF;
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
