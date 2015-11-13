/* Authors: Isak Nilsson, Hampus Liljekvist*/

#include "kmp.hpp"


void make_pi(const std::string & P, std::vector<long> & pi)
{
    // Bootstrap construction of state automaton that will keep
    // track of how long a suffix of the search string is currently
    // matched.
    const size_t m = P.length();
    for (size_t q = 2; q <= m; ++q)
    {
        long k = pi[q - 1];
        while ((k > 0) && (P[k] != P[q - 1]))
            k = pi[k];
        if (P[k] == P[q - 1])
            pi[q] = k + 1;
        else
            pi[q] = 0;
    }
}

void find(const std::string & pattern, std::vector<long> & indices,
          const std::string & text)
{
    std::vector<long> pi(pattern.length() + 1, 0); // 1 indexed
    const size_t m = pattern.length();
    const size_t n = text.length();
    size_t q = 0;

    make_pi(pattern, pi);

    // Continuously update state of automaton. Whenever end state is
    // reached, add index of found match and make epsilon transition.
    for (size_t i = 1; i <= n; i++)
    {
        while ((q > 0) && (pattern[q] != text[i - 1]))
            q = pi[q];
        if (pattern[q] == text[i - 1])
            ++q;
        if (q == m)
        {
            indices.push_back((i - m)); // 0 indexed
            q = pi[q];
        }
    }
}
