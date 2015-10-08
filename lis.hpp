/*
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#pragma once

#include <limits>
#include <vector>


/*
 * Find the longest increasing subsequence of positive integers.
 *
 * @param integers: A vector containing the full sequence.
 * @return:         The indices of the longest increasing subsequence.
 */
const std::vector<long int> lis(const std::vector<long int>&);
