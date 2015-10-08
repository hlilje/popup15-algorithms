/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once
#include "interval.hpp"
#include "union_find.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#define MAX_LINT std::numeric_limits<long int>::max()

typedef std::vector< std::vector<long int> > int_matrix;
typedef std::vector< std::pair<long int, long int> > int_pairs;


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
 * Decide the most profitable choice of items to pack.
 *
 * @param capacity:     The capacity of the knapsack.
 * @param value_weight: The value/weight pairs of items.
 * @return:             A vector of integers representing the indices of
 *                      chosen items.
 */
std::vector<long int> knapsack(const long int, const int_pairs&);

/**
 * Find the longest increasing subsequence of positive integers.
 *
 * @param integers: A vector containing the full sequence.
 * @return:         The indices of the longest increasing subsequence.
 */
const std::vector<long int> lis(const std::vector<long int>&);
