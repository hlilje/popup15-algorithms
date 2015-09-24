/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "algorithms.hpp"
#include "fenwick.hpp"
#include "interval.hpp"
#include "set.hpp"
#include "test_generator.hpp"
#include <iostream>
#include <vector>


/**
 * Solve the Kattis Fenwick Tree problem.
 */
void kattis_fenwick_tree()
{
    // Turn off sync with C I/O for speed
    std::iostream::sync_with_stdio(false);

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

/**
 * Solve the Kattis Interval Cover problem.
 */
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

/**
 * Solve the Kattis Longest Increasing Subsequence problem.
 */
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

/**
 * Solve the Kattis Union-Find problem.
 */
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

int main()
{
    /* kattis_interval_cover(); */
    /* kattis_longest_increasing_subsequence(); */
    /* kattis_fenwick_tree(); */
    kattis_union_find();
}
