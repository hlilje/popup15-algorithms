/* Authors: Isak Nilsson, Hampus Liljekvist */

#include <iostream>
#include <vector>


/*
 * Create the KMP automaton.
 *
 * @param P: The pattern to build from.
 * @param pi:      Vector to fill with state transition info.
 */
void make_pi(const std::string &, std::vector<long> &);

/*
 * Find start indices for all matching of `pattern` in `text`.
 *
 * @param pattern:  The pattern to match.
 * @param indicies: The indices of found matches.
 * @param text:     The text to match on.
 */
void find(const std::string &, std::vector<long> &, const std::string &);
