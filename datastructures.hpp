#pragma once


class Interval
{
    public:
        const long double _left;
        const long double _right;
        const int _index;

        Interval(long double, long double, int);

        const bool operator<(const Interval&) const;
};
