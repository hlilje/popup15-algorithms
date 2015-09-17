#include "datastructures.hpp"


Interval::Interval(const long double left, const long double right,
                   const int index) :
    _left(left), _right(right), _index(index)
{
}

const bool Interval::operator<(const Interval& other) const
{
    return _left < other._left;
}
