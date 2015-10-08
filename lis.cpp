/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "lis.hpp"

#define MAX_LINT std::numeric_limits<long int>::max()


const std::vector<long int> lis(const std::vector<long int>& integers)
{
    std::vector<long int> indices = {0};
    std::vector<long int> min_end = {integers.front()};
    std::vector<long int> parents(integers.size());
    parents[0] = MAX_LINT;

    for (long int i = 1; i < (long int) integers.size(); ++i)
    {
        long int selected = integers[i];

        if (selected > min_end.back())
        {
            min_end.push_back(selected);
            parents[i] = indices.back();
            indices.push_back(i);
        }
        else
        {
            // Find first element not less than selected
            auto it = std::lower_bound(min_end.begin(), min_end.end(), selected);
            long int ix = it - min_end.begin();
            min_end[ix] = selected;
            indices[ix] = i;
            if (ix > 0)
                parents[i] = indices[ix - 1];
            else
                parents[i] = MAX_LINT;
        }
    }

    // Backtrack to find the corresponding indices
    std::vector<long int> result;
    long int parent = indices.back();
    while (parent != MAX_LINT)
    {
        result.insert(result.begin(), parent);
        parent = parents[parent];
    }

    return result;
}
