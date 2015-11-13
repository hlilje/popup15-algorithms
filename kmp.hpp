/* Authors: Isak Nilsson, Hampus Liljekvist */

#include <iostream>
#include <vector>


/*
 * Create the KMP automaton.
 *
 * @param pattern: The pattern to build from.
 * @return:        A vector of epsilon state transitions.
 */
std::vector<long> make_pi(const std::string &);

/*
 * Find start indices for all matching of `pattern` in `text`.
 *
 * @param pattern: The pattern to match.
 * @param text:    The text to match on.
 * @return:        The matching indices.
 */
std::vector<long> find(const std::string &, const std::string &);
