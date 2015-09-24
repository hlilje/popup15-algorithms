/**
 * Authors: Hampus Liljekvist, Isak Nilsson
 */
#include "set.hpp"


set::set(const long int value) :
    // Recursion base case
    parent(this), rank(0), value(value) { }
