/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <iostream>


/*
 * Implementation of a 2D point.
 */
template <typename T>
class Point
{
    private:
        const T x, y;

    public:
        Point(const T x, const T y);

        /*
         * Point-wise addition.
         */
        Point operator+(const Point & rhs) const;

        /*
         * Point-wise subraction.
         */
        Point operator-(const Point & rhs) const;

        /*
         * Multiplication with scalar.
         * The resulting point will be of T type.
         */
        template <typename F>
        Point operator*(const F factor) const;

        /*
         * Division with scalar.
         * The resulting point will be of T type.
         */
        template <typename F>
        Point operator/(const F factor) const;

        /*
         * Dot product.
         */
        T dot_product(const Point & other) const;

        /*
         * Cross product.
         */
        T cross_product(const Point & other) const;

        /*
         * @return: The distance to other point.
         */
        double distance(const Point & other) const;

        /*
         * Compute the angle at point to the other two.
         *
         * @return: The angle between the three points.
         */
        double angle(const Point & p1, const Point & p2) const;

        template <typename V>
        friend std::ostream & operator<<(std::ostream & os, const Point<V> & pnt);
};

template <typename V>
std::ostream & operator<<(std::ostream & os, const Point<V> & pnt);


#include "point.cpp"

#endif
