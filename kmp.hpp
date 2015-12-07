/* Authors: Isak Nilsson, Hampus Liljekvist */

#pragma once

#include <string>
#include <vector>


/*
 * Create the KMP automaton.
 *
 * @param P:  The pattern to build from.
 * @param pi: Vector to fill with state transition info.
 */
void make_pi(const std::string &, std::vector<long> &);

/*
 * Find start indices for all matchings of `pattern` in `text`.
 *
 * @param pattern: The pattern to match.
 * @param indices: The indices of found matches.
 * @param text:    The text to match on.
 */
void find(const std::string &, std::vector<long> &, const std::string &);

/*
 * Find start indices for all matchings of all `patterns` in `text`.
 *
 * @param patterns: The patterns to match.
 * @param indices: The indices of found matches.
 * @param text:    The text to match on.
 */
void find(const std::vector<std::string> &, std::vector<std::vector<long>> &,
          const std::string &);
