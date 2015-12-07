/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GEOMETRY
#define GEOMETRY

#include "geometry.hpp"


template <typename T>
double simple_polygon_area(const std::vector<Point<T>> & points)
{
    double area = 0.0;

    for (size_t i = 0; i < points.size(); ++i)
    {
        Point<T> p1 = points[i];
        Point<T> p2 = points[(i + 1) % points.size()];

        area += p1.cross_product(p2);
    }

    return area / 2.0;
}

#endif
