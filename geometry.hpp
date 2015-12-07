/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "point.hpp"
#include <vector>


/*
 * Compute the simple polygon area.
 *
 * @param vertices:  Vector of points in clockwise/counter-clockwise order.
 * @return:          The signed area of the simple polygon.
 *                   Negative for clockwise input.
 */
template <typename T>
double simple_polygon_area(const std::vector<Point<T>> & vertices);

/*
 * Compute if the given point lies in the simple polygon.
 *
 * @param point:    The point to check.
 * @param vertices: The vertices of the polygon.
 * @return:
 * 0  => on polygon edge
 * 1  => inside polygon
 * -1 => outside polygon
 */
template <typename T>
int point_in_polygon(const Point<T> & point,
                     const std::vector<Point<T>> & vertices);


#include "geometry.cpp"

#endif
