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
    double tot_angle = 0.0;

    // Accumulate angles between point and vertex pairs
    for (size_t i = 0; i < vertices.size(); ++i)
    {
        Point<T> p1 = vertices[i];
        Point<T> p2 = vertices[(i + 1) % vertices.size()];

        double angle = point.angle(p1, p2);

        // Check for point on polygon side
        if (std::abs(angle) == M_PI) return 0;

        tot_angle += angle;
    }

    // Should be pi, but large margin for error
    if (std::abs(tot_angle) > M_PI / 2.0)
        return 1;
    else
        return -1;
}


#endif
