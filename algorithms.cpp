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

    while (min < max)
    {
        Interval part = parts[min];
        Interval best_part = part;
        std::cout << "Init best: " << best_part._left << " " << best_part._right << std::endl;

        if (min == max - 1)
        {
            if ((part._right < interval._right) || (part._left > left_coord))
            {
                indices.clear();
                break;
            }
        }

        // TODO: Double comparison
        if ((part._right >= interval._right) && (part._left <= left_coord))
        {
            if (indices.back() != part._index)
                indices.push_back(part._index);
            break;
        }

        while (part._left <= left_coord)
        {
            ++min;
            Interval next = parts[min];
            if ((next._right > best_part._right) && (next._left <= left_coord))
            {
                best_part = next;
                std::cout << "New best: " << best_part._left << " " << best_part._right << std::endl;
            }
            part = next;
        }

        indices.push_back(best_part._index);
        left_coord = best_part._right;
        std::cout << "Pushing: " << best_part._left << " " << best_part._right << std::endl;
    }

    return indices;
}
