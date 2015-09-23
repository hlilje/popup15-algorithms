/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include <iostream>
#include <vector>
#include "algorithms.hpp"
#include "interval.hpp"


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
    kattis_interval_cover();
    /* kattis_longest_increasing_subsequence(); */
}
