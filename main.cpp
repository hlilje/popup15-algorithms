/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "algorithms.hpp"
#include "datastructures.hpp"
#include <iostream>
#include <vector>


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
    unsigned int n;
    while (std::cin >> n)
    {
        std::cout << "n: " << n << std::endl;
        std::vector<unsigned int> integers(n);

        for (unsigned int i = 0; i < n; ++i)
            std::cin >> integers[i];

        for (auto& i : integers) std::cout << i << " ";
        std::cout << std::endl;

        std::vector<unsigned int> indices = lis(integers);
        for (auto& i : indices) std::cout << i << " ";
        std::cout << std::endl;
    }
}

int main()
{
    /* kattis_interval_cover(); */
    kattis_longest_increasing_subsequence();
}
