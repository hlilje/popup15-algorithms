/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "interval_cover.hpp"

typedef std::vector<std::vector<long int>> int_matrix;
typedef std::vector<std::pair<long int, long int>> int_pairs;



Interval::Interval() : _left(0.0), _right(0.0), _index(-1)
{
}

Interval::Interval(const long double left, const long double right,
                   const int index) :
    _left(left), _right(right), _index(index)
{
}

Interval::~Interval()
{
}

Interval& Interval::operator=(const Interval& other)
{
    _left = other._left;
    _right = other._right;
    _index = other._index;

    return *this;
}

bool Interval::operator<(const Interval& other) const
{
    return _left < other._left;
}


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
