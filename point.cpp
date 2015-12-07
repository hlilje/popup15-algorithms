/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef POINT
#define POINT

#include "point.hpp"


template <typename T>
Point<T>::Point(const T x, const T y) : x(x), y(y) {}

template <typename T>
Point<T> Point<T>::operator+(const Point & rhs) const
{
    return Point(x + rhs.x, y + rhs.y);
}

template <typename T>
Point<T> Point<T>::operator-(const Point & rhs) const
{
    return Point(x - rhs.x, y - rhs.y);
}

template <typename T>
template <typename F>
Point<T> Point<T>::operator*(const F factor) const
{
    return Point(factor * x, factor * y);
}

template <typename T>
template <typename F>
Point<T> Point<T>::operator/(const F factor) const
{
    return Point(x / factor, y / factor);
}

template <typename T>
T Point<T>::dot_product(const Point & other) const
{
    return x * other.x + y * other.y;
}

template <typename T>
T Point<T>::cross_product(const Point & other) const
{
    return x * other.y - y * other.x;
}

template <typename T>
double Point<T>::distance(const Point & other) const
{
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
}

template <typename T>
double Point<T>::angle(const Point & p1, const Point & p2) const
{
    Point<T> v1 = p1 - *this;
    Point<T> v2 = p2 - *this;

    return std::atan2(v1.cross_product(v2), v1.dot_product(v2));
}

template <typename V>
std::ostream & operator<<(std::ostream& os, const Point<V> & pnt)
{
    os << '(' << pnt.x << ", " << pnt.y << ')';
    return os;
}

#endif
