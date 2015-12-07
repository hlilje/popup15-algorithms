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
 * @param:  Vector of points in clockwise/counter-clockwise order.
 * @return: The signed area of the simple polygon. Negative for clockwise input.
 */
template <typename T>
double simple_polygon_area(const std::vector<Point<T>> & points);


#include "geometry.cpp"

#endif
