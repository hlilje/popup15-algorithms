/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "datastructures.hpp"


/**
 * Try to cover the given full interval using the interval parts.
 *
 * @param interval: The full interval to cover.
 * @param parts:    The available intervals.
 * @return:         Indices of the intervals used, an empty array if the
 *                  interval could not be covered.
 */
const std::vector<int> cover(const Interval&, std::vector<Interval>&);
