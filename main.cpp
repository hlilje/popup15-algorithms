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
        std::vector<Interval> parts;
        for (int i = 0; i < n; ++i)
        {
            long double left, right;
            std::cin >> left >> right;
            parts.push_back(Interval(left, right, i));
        }

        std::vector<int> indices = cover(interval, parts);

        if (parts.size() == 0)
            std::cout << "impossible" << std::endl;
        else
        {
            std::cout << indices.size() << std::endl;
            for (auto i : indices) std::cout << i << " ";
            std::cout <<  std::endl;
        }
    }
}

int main()
{
    kattis_interval_cover();
}
