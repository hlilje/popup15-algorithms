/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once


/**
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
