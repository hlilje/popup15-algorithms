/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GEOMETRY
#define GEOMETRY

#include "geometry.hpp"


template <typename T>
double simple_polygon_area(const std::vector<Point<T>> & vertices)
{
    double area = 0.0;

    // Accumulate parallelogram areas for each pair of vertices
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        Point<T> p1 = vertices[i];
        Point<T> p2 = vertices[(i + 1) % vertices.size()];

        area += p1.cross_product(p2);
    }

    // Divide by 2 for triangles, not parallelograms
    return area / 2.0;
}

template <typename T>
int point_in_polygon(const Point<T> & point,
                     const std::vector<Point<T>> & vertices)
{
    return 0;
}


#endif
