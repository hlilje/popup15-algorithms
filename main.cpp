/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
/* #include "fenwick.hpp" */
#include "graph.hpp"
/* #include "interval_cover.hpp" */
/* #include "knapsack.hpp" */
/* #include "lis.hpp" */
/* #include "test_generator.hpp" */
/* #include "union_find.hpp" */
/* #include <cassert> */
#include <iostream>
/* #include <vector> */


/*
 * Solve the Kattis Fenwick Tree problem.
 */
/*
void kattis_fenwick_tree()
{
    long long int N, Q; std::cin >> N >> Q;
    fenwick tree(N + 1);

    for (long long int i = 0; i < Q; ++i)
    {
        char op;
        std::cin >> op;
        if (op == '+')
        {
            long long int i, delta; std::cin >> i >> delta;
            tree.add(i, delta);
        }
        else if (op == '?')
        {
            long long int i; std::cin >> i;
            std::cout << tree.sum(i) << std::endl;
        }
    }
}
*/

/*
 * Solve the Kattis Interval Cover problem.
 */
/*
void kattis_interval_cover()
{
    long double A, B;
    int n;

    while (std::cin >> A >> B >> n)
    {
        Interval interval(A, B, -1);
        std::vector<Interval> parts(n);
        for (int i = 0; i < n; ++i)
        {
            long double left, right;
            std::cin >> left >> right;
            parts[i] = Interval(left, right, i);
        }

        std::vector<int> indices = cover(interval, parts);

        if (indices.size() == 0)
            std::cout << "impossible" << std::endl;
        else
        {
            std::cout << indices.size() << std::endl;
            for (auto& i : indices) std::cout << i << " ";
            std::cout <<  std::endl;
        }
    }
}
*/

/*
 * Solve the Kattis Knapsack problem.
 */
/*
void kattis_knapsack()
{
    double C_dbl; // Capacity
    long int n;        // Num objects
    while (std::cin >> C_dbl >> n)
    {
        long int C = (long int) C_dbl; // Weights are long integers
        std::vector<std::pair<long int, long int>> value_weight(n);
        for (long int i = 0; i < n; ++i)
        {
            long int value, weight; std::cin >> value >> weight;
            value_weight[i] = std::pair<long int, long int>(value, weight);
        }

        std::vector<long int> indices = knapsack(C, value_weight);

        assert(indices.size() > 0);

        std::cout << indices.size() << std::endl;
        for (const auto& ix : indices)
            std::cout << ix << " ";
        std::cout << std::endl;
    }
}
*/

/*
 * Solve the Kattis Longest Increasing Subsequence problem.
 */
/*
void kattis_longest_increasing_subsequence()
{
    long int n;
    while (std::cin >> n)
    {
        std::vector<long int> integers(n);

        for (long int i = 0; i < n; ++i)
            std::cin >> integers[i];

        std::vector<long int> indices = lis(integers);
        std::cout << indices.size() << std::endl;
        for (auto& i : indices) std::cout << i << " ";
        std::cout << std::endl;
    }
}
*/

/*
 * Solve the Kattis Single Source Shortest Path, Non-Negative Weights problem.
 * Additionally solves the construction problem.
 */
/*
void kattis_shortest_path_non_neg()
{
    long n, m, q, s;
    while (std::cin >> n >> m >> q >> s)
    {
        if (n == 0 && m == 0 && q == 0 && s == 0)
            break;

        Graph<long> graph(n);
        for (long i = 0; i < m; ++i)
        {
            // Assume simple graph
            long u, v, w; std::cin >> u >> v >> w;
            Edge<long>* edge = new Edge<long>(w, u, v, 0, 0);
            graph.out_edges[u].push_back(edge);
        }
        std::pair<std::vector<long>, std::vector<long>> parents_dist =
                shortest_path(graph, s);
        std::vector<long> dist = parents_dist.second;
        for (long i = 0; i < q; ++i)
        {
            long target; std::cin >> target;
            long distance = dist[target];
            if (distance != std::numeric_limits<long>::max() / 100)
                std::cout << distance << std::endl;
            else
                std::cout << "Impossible" << std::endl;
        }
        for (const auto& edge_list : graph.out_edges)
            for (const auto& edge : edge_list)
                delete edge;
        std::cout << std::endl;
    }
}
*/

/*
 * Solve the Kattis Single Source Shortest Path, Time Table problem.
 * Additionally solves the construction problem.
 */
void kattis_shortest_path_time_table()
{
    long n, m, q, s;
    while (std::cin >> n >> m >> q >> s)
    {
        if (n == 0 && m == 0 && q == 0 && s == 0)
            break;

        Graph<long> graph(n);
        for (long i = 0; i < m; ++i)
        {
            // Assume simple graph
            long u, v, t_0, P, d; std::cin >> u >> v >> t_0 >> P >> d;
            Edge<long>* edge = new Edge<long>(d, u, v, t_0, P);
            graph.out_edges[u].push_back(edge);
        }
        std::pair<std::vector<long>, std::vector<long>> parents_dist =
                shortest_path_time(graph, s);
        std::vector<long> dist = parents_dist.second;
        for (long i = 0; i < q; ++i)
        {
            long target; std::cin >> target;
            long distance = dist[target];
            if (distance != std::numeric_limits<long>::max() / 100)
                std::cout << distance << std::endl;
            else
                std::cout << "Impossible" << std::endl;
        }
        for (const auto& edge_list : graph.out_edges)
            for (const auto& edge : edge_list)
                delete edge;
        std::cout << std::endl;
    }
}

/*
 * Solve the Kattis Union-Find problem.
 */
/*
void kattis_union_find()
{
    long int N, Q; std::cin >> N >> Q;
    std::vector<set*> sets(N);

    for (long int i = 0; i < N; ++i)
        sets[i] = new set(i + 1);

    for (long int i = 0; i < Q; ++i)
    {
        char op;
        long int a, b;
        std::cin >> op >> a >> b;

        if (op == '=')
        {
            set_union(sets[a], sets[b]);
        }
        else if (op == '?')
        {
            if (same(sets[a], sets[b]))
                std::cout << "yes" << std::endl;
            else
                std::cout << "no" << std::endl;
        }
    }

    for (long int i = 0; i < N; ++i)
        delete sets[i];
}
*/

int main()
{
    // Turn off sync with C I/O for speed
    std::cin.sync_with_stdio(false);

    /* kattis_interval_cover(); */
    /* kattis_longest_increasing_subsequence(); */
    /* kattis_fenwick_tree(); */
    /* kattis_union_find(); */
    /* kattis_knapsack(); */
    /* kattis_shortest_path_non_neg(); */
    kattis_shortest_path_time_table();
}
