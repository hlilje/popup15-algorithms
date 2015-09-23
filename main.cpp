/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include <iostream>
#include <vector>
#include "algorithms.hpp"
#include "fenwick.hpp"
#include "interval.hpp"


/**
 * Solve the Kattis Fenwick Tree problem.
 */
void kattis_fenwick_tree()
{
    long long int N, Q;
    std::cin >> N >> Q;
    std::cout << N << " " << Q << std::endl;
    for (long long int i = 0; i < Q; ++i)
    {
        std::string op;
        std::cin >> op;
        if (op.compare("+") == 0)
        {
            long long int i, delta;
            std::cin >> i >> delta;
            std::cout << i << " " << delta << std::endl;
        }
        else if (op.compare("?") == 0)
        {
            long long int i;
            std::cin >> i;
            std::cout << i << std::endl;
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

int main()
{
    /* kattis_interval_cover(); */
    /* kattis_longest_increasing_subsequence(); */
    kattis_fenwick_tree();
}
