#include "datastructures.hpp"
#include <iostream>
#include <vector>


void kattis_interval_cover()
{
    long double A, B;
    int n;

    while (std::cin >> A >> B >> n)
    {
        std::vector<Interval> parts;
        for (int i = 0; i < n; ++i)
        {
            long double left, right;
            std::cin >> left >> right;
            parts.push_back(Interval(left, right, i));
        }
        std::cout << parts.size() << std::endl;
    }
}

int main()
{
    kattis_interval_cover();
}
