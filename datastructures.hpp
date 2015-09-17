#pragma once


class Interval
{
    public:
        long double _left;
        long double _right;
        int _index;

        Interval();
        Interval(long double, long double, int);
        ~Interval();

        Interval& operator=(const Interval&);
        bool operator<(const Interval&) const;
};
