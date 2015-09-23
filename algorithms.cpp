/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "algorithms.hpp"


const std::vector<int> cover(const Interval& interval,
                             std::vector<Interval>& parts)
{
    int min = 0;
    int max = parts.size();
    long double left_coord = interval._left;
    std::vector<Interval> original_parts = parts;
    std::vector<int> indices;

    std::sort(parts.begin(), parts.end());

    // Special case for point interval
    if (interval._left == interval._right)
    {
        for (unsigned int i = 0; i < parts.size(); ++i)
        {
            Interval part = parts[i];
            if ((interval._left >= part._left) && (interval._right <= part._right))
            {
                indices.push_back(part._index);
                break;
            }
        }
        return indices;
    }

    while ((left_coord < interval._right) && (min < max))
    {
        Interval part = parts[min];
        Interval best_part = part;

        while ((part._left <= left_coord) && (min < max - 1))
        {
            ++min;
            Interval next = parts[min];
            if ((next._right > best_part._right) && (next._left <= left_coord))
                best_part = next;
            part = next;
        }

        if ((best_part._left > left_coord) || best_part._right <= left_coord)
            break;

        indices.push_back(best_part._index);
        left_coord = best_part._right;
    }

    // Since the last part is always added, verify that it is legit
    if ((max > 0) && (indices.size() > 0))
    {
        Interval last = original_parts[indices.back()];
        if ((last._left > left_coord) || (last._right < interval._right))
            indices.clear();
    }

    return indices;
}

const std::vector<unsigned int> lis(const std::vector<unsigned int>& integers)
{
    std::vector<unsigned int> indices = {0};
    std::vector<unsigned int> min_end = {integers.front()};
    std::vector<int> parents(integers.size());
    parents[0] = MAX_UINT;

    std::cout << "========" << std::endl;

    for (unsigned int i = 1; i < integers.size(); ++i)
    {
        unsigned int selected = integers[i];

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
            unsigned int ix = it - min_end.begin();
            min_end[ix] = selected;
            indices[ix] = i;
            if (ix > 0)
                parents[i] = indices[ix - 1];
            else
                parents[i] = MAX_UINT;
        }
        for (auto& i : min_end) std::cout << i << " ";
        std::cout << std::endl;
    }

    std::cout << "========" << std::endl;

    // Backtrack to find the corresponding indices
    std::vector<unsigned int> result;
    unsigned int parent = indices.back();
    while (parent != MAX_UINT)
    {
        result.insert(result.begin(), parent);
        parent = parents[parent];
    }

    return result;
}
