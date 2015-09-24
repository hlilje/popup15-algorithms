/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once
#include "interval.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#define MAX_LINT std::numeric_limits<long int>::max()


/**
 * Try to cover the given full interval using the interval parts.
 * Assume the intervals are distinguishable as doubles.
 *
 * @param interval: The full interval to cover.
 * @param parts:    The available intervals.
 * @return:         Indices of the intervals used, an empty array if the
 *                  interval could not be covered.
 */
const std::vector<int> cover(const Interval&, std::vector<Interval>&);

/**
 * Find the longest increasing subsequence of positive integers.
 *
 * @param integers: A vector containing the full sequence.
 * @return:         The indices of the longest increasing subsequence.
 */
const std::vector<long int> lis(const std::vector<long int>&);
