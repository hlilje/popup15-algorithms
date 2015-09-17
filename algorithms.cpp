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
                indices.push_back(i);
                break;
            }
        }
        return indices;
    }

    // TODO: Double comparison
    while ((left_coord < interval._right) && (min < max))
    {
        Interval part = parts[min];
        Interval best_part = part;
        /* std::cout << "Init best: " << best_part._left << " " << best_part._right << std::endl; */

        while ((part._left <= left_coord) && (min < max - 1))
        {
            ++min;
            Interval next = parts[min];
            /* std::cout << "next: " << next._left << " " << next._right << std::endl; */
            if ((next._right > best_part._right) && (next._left <= left_coord))
            {
                best_part = next;
                /* std::cout << "New best: " << best_part._left << " " << best_part._right << std::endl; */
            }
            part = next;
        }

        if ((best_part._left > left_coord) || best_part._right <= left_coord)
            break;

        indices.push_back(best_part._index);
        left_coord = best_part._right;
        /* std::cout << "Pushing: " << best_part._left << " " << best_part._right << std::endl; */
    }

    // Since the last part is always added, verify that it is legit
    if ((max > 0) && (indices.size() > 0))
    {
        Interval last = parts[indices.back()];
        if ((last._left > left_coord) || (last._right < interval._right))
            indices.clear();
    }

    return indices;
}
