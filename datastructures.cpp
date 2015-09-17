/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "datastructures.hpp"


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
