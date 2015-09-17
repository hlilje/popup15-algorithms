#include "algorithms.hpp"


/**
 * Cover the given full interval using the interval parts.
 *
 * @param interval: The full interval to cover.
 * @param parts: The available intervals.
 * @return: Indices of the intervals used, an empty array if the interval could
 *          not be covered.
 */
const std::vector<int> cover(const Interval& interval,
                             std::vector<Interval>& parts)
{
    int min = 0;
    int max = parts.size();
    long double left_coord = 0.0;
    std::vector<int> indices;

    std::sort(parts.begin(), parts.end());

    while (min < max)
    {
        Interval part = parts[min];
        Interval best_part = part;

        if (min == max - 1)
        {
            if ((part._right < interval._right) || (part._left > left_coord))
            {
                indices.clear();
                break;
            }
        }

        // TODO: Double comparison
        if (part._right >= interval._right)
            return indices;

        while (part._left <= left_coord)
        {
            ++min;
            Interval next = parts[min];
            if ((next._right > best_part._right) && (next._left <= left_coord))
                best_part = next;
            part = next;
        }

        indices.push_back(best_part._index);
    }

    return indices;
}
