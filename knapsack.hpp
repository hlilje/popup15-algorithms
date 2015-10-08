/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once

#include <vector>


/*
 * Decide the most profitable choice of items to pack.
 *
 * @param capacity:     The capacity of the knapsack.
 * @param value_weight: The value/weight pairs of items.
 * @return:             A vector of integers representing the indices of
 *                      chosen items.
 */
std::vector<long int> knapsack(const long int,
                               const std::vector<std::pair<long int, long int>>&);
