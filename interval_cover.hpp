/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once

#include <algorithm>
#include <vector>


/*
 * Represents a closed interval [_left, _right].
 */
class Interval
{
    public:
        long double _left;  // Left bound of interval (inclusive)
        long double _right; // Right bound of interval (inclusive)
        int _index;         // Interval index

        Interval();

        /**
         * @param left:  Left interval bound (inclusive).
         * @param right: Right interval bound (inclusive).
         * @param index: Interval index.
         */
        Interval(long double, long double, int);

        ~Interval();

        Interval& operator=(const Interval&);

        bool operator<(const Interval&) const;
};


/*
 * Try to cover the given full interval using the interval parts.
 * Assume the intervals are distinguishable as doubles.
 *
 * @param interval: The full interval to cover.
 * @param parts:    The available intervals.
 * @return:         Indices of the intervals used, an empty array if the
 *                  interval could not be covered.
 */
const std::vector<int> cover(const Interval&, std::vector<Interval>&);
